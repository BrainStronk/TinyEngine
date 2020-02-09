#include <stdio.h>
#include <windows.h>

static void
Print(char* Format, ...)
{
    static char Buffer[1024];
    va_list ArgumentList;
    va_start(ArgumentList, Format);
    vsprintf_s(Buffer, sizeof(Buffer), Format, ArgumentList);
    va_end(ArgumentList);
    OutputDebugStringA(Buffer);
}