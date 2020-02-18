#define LINUX_LEAN_AND_MEAN
#define VK_USE_PLATFORM_XLIB_KHR
#define TINYENGINE_DEBUG

#include <X11/Xlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "tinyengine.h"
#include "tiny_vulkan.h"

/*
To avoid naming conflicts and ability to create more than 1 window -
this is a struct.
*/
typedef struct linux_wnd
{ 
	Display* Display;
	Window Window;
	XSetWindowAttributes Attr;
	Drawable RootWindow;
	s32 Screen;
	u32 Width;
	u32 Height; 
	u32 Xpos;
	u32 Ypos;
	u32 BorderWidth;
	u32 Depth;
	u32 ValueMask;
} linux_wnd;

static linux_wnd Wnd;

void SurfaceCallback(VkSurfaceKHR* Surface)
{
	XWindowAttributes Attr;
	XGetWindowAttributes(Wnd.Display, Wnd.Window, &Attr);
	Wnd.Width = Attr.width;
	Wnd.Height = Attr.height;
	SetSizeOfSwapchainImages(Wnd.Width, Wnd.Height);

	if(Surface)
	{
		VkXlibSurfaceCreateInfoKHR SurfaceCI;
		SurfaceCI.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
		SurfaceCI.pNext = NULL;
		SurfaceCI.flags = 0;
		SurfaceCI.dpy = Wnd.Display;
		SurfaceCI.window = Wnd.Window;

		VK_CHECK(vkCreateXlibSurfaceKHR(Instance, &SurfaceCI, NULL, Surface));
	}
}

#ifdef TINYENGINE_DEBUG
#define DbgEvent Debug
#endif

int main(int argc, char** argv)
{
	log_set_level(0);
	FILE* f = fopen("./log.txt","w");
	log_set_fp(f);

	Wnd.Display = XOpenDisplay(getenv("DISPLAY"));
	if (Wnd.Display == NULL)
	{
		Fatal("Cannot open display!");
		exit(1);
	}

	Wnd.Screen = XDefaultScreen(Wnd.Display);

	Wnd.Attr.background_pixel = XBlackPixel(Wnd.Display, Wnd.Screen);
	Wnd.ValueMask |= CWBackPixel;
	Wnd.Depth = DefaultDepth(Wnd.Display, Wnd.Screen);
	Wnd.RootWindow = RootWindow(Wnd.Display, DefaultScreen(Wnd.Display));
	Wnd.Width = 640;
	Wnd.Height = 640;
	Wnd.Xpos = 0;
	Wnd.Ypos = 0;
	Wnd.BorderWidth = 0;
	Wnd.Window = XCreateWindow(Wnd.Display, XRootWindow(Wnd.Display, Wnd.Screen),
			Wnd.Xpos, Wnd.Ypos, Wnd.Width, Wnd.Height,
			Wnd.BorderWidth, Wnd.Depth, InputOutput,
			DefaultVisual(Wnd.Display, Wnd.Screen),
			Wnd.ValueMask, &Wnd.Attr);


	const char *RequiredExtensions[] =
	{
		VK_KHR_SURFACE_EXTENSION_NAME,
		VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
#ifdef TINYENGINE_DEBUG
		VK_EXT_DEBUG_REPORT_EXTENSION_NAME
#endif
	};

	void* VulkanLoader = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_DEEPBIND);
	PFN_vkGetInstanceProcAddr ProcAddr = dlsym(VulkanLoader, "vkGetInstanceProcAddr");
	if(!InitVulkan(&ProcAddr, SurfaceCallback, ArrayCount(RequiredExtensions), RequiredExtensions))
	{
		Fatal("Failed to initialize vulkan runtime!");
		exit(1);
	}


	XSelectInput(Wnd.Display, Wnd.Window, ExposureMask | KeyPressMask);
	XMapWindow(Wnd.Display, Wnd.Window);

	// Set window title
	XStoreName(Wnd.Display, Wnd.Window, "TinyEngine");

	XEvent Event;
	while (1) 
	{
		//see https://tronche.com/gui/x/xlib/events/structures.html 
		//TODO(Kyryl): These events prevent the renderer from execution. 
		//Fork it or multithread.
		//XNextEvent(Wnd.Display, &Event);

		switch(Event.type)
		{
			case KeyPress:
				DbgEvent("KeyPress");
				break;
			case KeyRelease:
				DbgEvent("KeyRelease");
				break;
			case ButtonPress:
				DbgEvent("KeyPress");
				break;
			case ButtonRelease:
				DbgEvent("KeyPress");
				break;
			case MotionNotify:
				DbgEvent("MotionNotify");
				break;
			case EnterNotify:
				DbgEvent("EnterNotify");
				break;
			case LeaveNotify:
				DbgEvent("LeaveNotify");
				break;
			case FocusIn:
				DbgEvent("FocusIn");
				break;
			case FocusOut:
				DbgEvent("FocusOut");
				break;
			case KeymapNotify:
				DbgEvent("KeymapNotify");
				break;
			case Expose:;
				DbgEvent("Expose");
				break;
			case GraphicsExpose:
				DbgEvent("GraphicsExpose");
				break;
			case NoExpose:
				DbgEvent("NoExpose");
				break;
			case VisibilityNotify:
				DbgEvent("VisibilityNotify");
				break;
			case CreateNotify:
				DbgEvent("CreateNotify");
				break;
			case DestroyNotify:
				DbgEvent("DestroyNotify");
				break;
			case UnmapNotify:
				DbgEvent("UnmapNotify");
				break;
			case MapNotify:
				DbgEvent("MapNotify");
				break;
			case MapRequest:
				DbgEvent("MapRequest");
				break;
			case ReparentNotify:
				DbgEvent("ReparentNotify");
				break;
			case ConfigureNotify: ;
				DbgEvent("ConfigureNotify");
				break;
			case ConfigureRequest: ;
				DbgEvent("ConfigureRequest");
				break;
			case GravityNotify:
				DbgEvent("GravityNotify");
				break;
			case ResizeRequest:
				DbgEvent("ResizeRequest");
				//Does not work? 
				break;
		}
		VkBeginRendering();
		//DRAW commands go in between Begin and End respectively.

		Vertex vertices[4] = {0};
		vertices[0].pos[0] = -0.5f;   //x
		vertices[0].pos[1] = -0.5f;   //y
		vertices[0].color[0] = 1.0f; //r
		vertices[0].color[1] = 0.0f; //g
		vertices[0].color[2] = 0.0f; //b
		vertices[0].tex_coord[0] = 1.0f;
		vertices[0].tex_coord[1] = 0.0f;

		vertices[1].pos[0] = 0.5f;
		vertices[1].pos[1] = -0.5f;
		vertices[1].color[0] = 0.0f;
		vertices[1].color[1] = 1.0f;
		vertices[1].color[2] = 0.0f;
		vertices[1].tex_coord[0] = 0.0f;
		vertices[1].tex_coord[1] = 0.0f;

		vertices[2].pos[0] = 0.5f;
		vertices[2].pos[1] = 0.5f;
		vertices[2].color[0] = 0.0f;
		vertices[2].color[1] = 0.0f;
		vertices[2].color[2] = 1.0f;
		vertices[2].tex_coord[0] = 0.0f;
		vertices[2].tex_coord[1] = 1.0f;

		vertices[3].pos[0] = -0.5f;
		vertices[3].pos[1] = 0.5f;
		vertices[3].color[0] = 1.0f;
		vertices[3].color[1] = 1.0f;
		vertices[3].color[2] = 1.0f;
		vertices[3].tex_coord[0] = 1.0f;
		vertices[3].tex_coord[1] = 1.0f;

		u32 indeces[6] = {0, 1, 2, 2, 3, 0};
		DrawBasic(ArrayCount(vertices), &vertices[0], ArrayCount(indeces), &indeces[0]);
		VkEndRendering();
	}

	XCloseDisplay(Wnd.Display);
	return 0;
}

