#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <io.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_RECT_PACK_IMPLEMENTATION
#include "stb_rect_pack.h"

// S O R T //////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SortAscending(void*, void*);
int 
SortAscending(void *P1, void *P2)
{
	return(*(int*)P1 - *(int*)P2);
}
 
int SortDescending(void*, void*);
int 
SortDescending(void* P1, void *P2)
{
	return(*(int*)P2 - *(int*)P1);
}

// D I R E C T O R Y ////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct directory
{
    struct _finddata_t FindData;
    intptr_t FindHandle;
} directory;

directory
OpenDirectory(char* BaseDirectory)
{
    directory Result = {0};

    size_t StringLength = strlen(BaseDirectory);
    char *Wildcard = strchr("/\\", BaseDirectory[StringLength-1]) ? "*" : "/*";

    size_t FullWildcardPathSize = StringLength + strlen(Wildcard) + 1;
    char *FullWildcardPath = (char *)malloc(FullWildcardPathSize);
    if(FullWildcardPath)
    {
        strcpy_s(FullWildcardPath, FullWildcardPathSize, BaseDirectory);
        strcat_s(FullWildcardPath, FullWildcardPathSize, Wildcard);
        if((Result.FindHandle = _findfirst(FullWildcardPath, &Result.FindData)) == 0)
        {
            printf("Failed to find any files when searching for \"%s\"\n", FullWildcardPath);
        }
    }

    return(Result);
}

bool
ReadDirectory(directory *Directory)
{
    bool Error = false;

    if(_findnext(Directory->FindHandle, &Directory->FindData) != 0)
    {
        Error = true;
    }

    return(Error);
}

void
CloseDirectory(directory *Directory)
{
    if(Directory->FindHandle)
    {
        _findclose(Directory->FindHandle);
    }
}

// E X T E N S I O N ////////////////////////////////////////////////////////////////////////////////////////////////////

char*
GetFileExtension(char *Filename)
{
    char* Result;

    char* Dot = strrchr(Filename, '.');
    if(!Dot || Dot == Filename)
    {
        Result = "";
    }
    else
    {
        Result = Dot + 1;
    }

    return(Result);
}

// M A I N //////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct image
{
    unsigned char* Data;
    char Filename[_MAX_PATH];
    int ComponentsPerPixel;
    stbrp_rect* Rectangle;
} image;

#define BASE_DIRECTORY "../source/"
#define PACKED_IMAGE_WIDTH  2000
#define PACKED_IMAGE_HEIGHT 2000

image Images[8192];
unsigned int ImagesIndex;
stbrp_rect STBRPRects[8192];

int
main(int argc, char* argv[])
{
    // Create list of all png files within the directory

    directory Directory = OpenDirectory(BASE_DIRECTORY);
    while(ReadDirectory(&Directory) == 0)
    {
        if(strcmp(GetFileExtension(Directory.FindData.name), "png") == 0)
        {
            strcat_s(Images[ImagesIndex].Filename, _MAX_PATH, BASE_DIRECTORY);
            strcat_s(Images[ImagesIndex].Filename, _MAX_PATH, Directory.FindData.name);
            Images[ImagesIndex].Rectangle = &STBRPRects[ImagesIndex];
            Images[ImagesIndex].Data = stbi_load(Images[ImagesIndex].Filename, (int *)(unsigned int*)&Images[ImagesIndex].Rectangle->w, (int*)(unsigned int*)&Images[ImagesIndex].Rectangle->h, &Images[ImagesIndex].ComponentsPerPixel, 4);
            Images[ImagesIndex].Rectangle->id = ImagesIndex;
            ImagesIndex++;
        }
    }
    CloseDirectory(&Directory);

    stbrp_context STBRPContext = {0};
    int STBRPNumNodes = PACKED_IMAGE_WIDTH * PACKED_IMAGE_HEIGHT;
    stbrp_node* STBRPNodes = (stbrp_node*)malloc(sizeof(stbrp_node) * STBRPNumNodes);
    stbrp_init_target(&STBRPContext, PACKED_IMAGE_WIDTH, PACKED_IMAGE_HEIGHT, STBRPNodes, STBRPNumNodes);
    if(stbrp_pack_rects(&STBRPContext, STBRPRects, ImagesIndex) != true)
    {
        printf("Failed to pack rects with stbrp_pack_rects()! Are the defined PACKED_IMAGE dimensions too small?\n");
        return(1);
    }

    int32_t* ConsolidatedImage = (int32_t*)malloc(sizeof(int32_t)*STBRPNumNodes);
    for(unsigned int PackedImagesIndex = 0; PackedImagesIndex < ImagesIndex; ++PackedImagesIndex)
    {
        assert(Images[PackedImagesIndex].Rectangle->was_packed);

        int X = Images[PackedImagesIndex].Rectangle->x;
        int Y = Images[PackedImagesIndex].Rectangle->y;
        int W = Images[PackedImagesIndex].Rectangle->w;
        int H = Images[PackedImagesIndex].Rectangle->h;

        int32_t* ConsolidatedImagePointer = &ConsolidatedImage[Y*PACKED_IMAGE_WIDTH + X];
        int32_t* LeftSideIndex = ConsolidatedImagePointer;
        int32_t* ImagesData32 = (int32_t*)Images[PackedImagesIndex].Data;

        for(int Height = 0; Height < H; ++Height)
        {
            for(int Width = 0; Width < W; ++Width)
            {
                *ConsolidatedImagePointer++ = *ImagesData32++;
            }
            ConsolidatedImagePointer = LeftSideIndex + PACKED_IMAGE_WIDTH*Height;
        }
    }

    if(!stbi_write_png("packed_image.png", PACKED_IMAGE_WIDTH, PACKED_IMAGE_HEIGHT, 4, ConsolidatedImage, PACKED_IMAGE_WIDTH*4))
    {
        printf("stb_write_png() failed!\n");
        return(2);
    }

    char PackedImageLocationsFileDirectory[_MAX_PATH] = BASE_DIRECTORY;
    strcat_s(PackedImageLocationsFileDirectory, _MAX_PATH, "packed_image_locations.txt");

    FILE* PackedImageLocationsHandle = {0};
    fopen_s(&PackedImageLocationsHandle, PackedImageLocationsFileDirectory, "wb");
    for(unsigned int WriteImagesIndex = 0; WriteImagesIndex < ImagesIndex; ++WriteImagesIndex)
    {
        fputs(Images[WriteImagesIndex].Filename, PackedImageLocationsHandle);
        fputc('\n', PackedImageLocationsHandle);

        char ShortToChar[10] = {0};

        sprintf_s(ShortToChar, sizeof(ShortToChar), "%d", Images[WriteImagesIndex].Rectangle->x);
        fputs(ShortToChar, PackedImageLocationsHandle);
        fputc('\n', PackedImageLocationsHandle);

        sprintf_s(ShortToChar, sizeof(ShortToChar), "%d", Images[WriteImagesIndex].Rectangle->y);
        fputs(ShortToChar, PackedImageLocationsHandle);
        fputc('\n', PackedImageLocationsHandle);

        sprintf_s(ShortToChar, sizeof(ShortToChar), "%d", Images[WriteImagesIndex].Rectangle->w);
        fputs(ShortToChar, PackedImageLocationsHandle);
        fputc('\n', PackedImageLocationsHandle);

        sprintf_s(ShortToChar, sizeof(ShortToChar), "%d", Images[WriteImagesIndex].Rectangle->h);
        fputs(ShortToChar, PackedImageLocationsHandle);
        fputc('\n', PackedImageLocationsHandle);

        fputc('\n', PackedImageLocationsHandle);
    }

    fputc(-1, PackedImageLocationsHandle);

    return(0);
}