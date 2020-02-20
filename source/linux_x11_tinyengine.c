#define LINUX_LEAN_AND_MEAN
#define VK_USE_PLATFORM_XLIB_KHR
#define TINYENGINE_DEBUG

#include <X11/Xlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "tinyengine.h"
#include "tiny_vulkan.h"

static const char *level_names[] =
{
	"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL","TLOG"
};

#ifdef LOG_USE_COLOR
static const char *level_colors[] =
{
	"\x1b[94m", "\x1b[36m", "\x1b[32m", "\x1b[33m", "\x1b[31m", "\x1b[35m", "\x1b[94m"
};
#endif

void LogSetfp(FILE *Fp)
{
	Logfp = Fp;
}


void LogSetLevel(s32 Level)
{
	LogLevel = Level;
}

void FormatString(char* Buf, char* Str, ...)
{
	va_list Args;
	va_start(Args, Str);
	stbsp_vsprintf(Buf, Str, Args);
	va_end(Args);
}

void LogLog(s32 Level, const char *File, s32 Line, const char *Fmt, ...)
{
	if (Level < LogLevel)
	{
		return;
	}

	static volatile b32 Lock = 0;

	while(Lock){}; //cheap spinlock

	Lock = 1;

	s8 Buffer[1024];

	/* Get current time */
	time_t t = time(NULL);
	struct tm *lt = localtime(&t);

	/* Log to terminal */
	if (!LogQuiet)
	{
		va_list args;
		if(LogExtra)
		{
			char buf[16];
			buf[strftime(buf, sizeof(buf), "%H:%M:%S", lt)] = '\0';
#ifdef LOG_USE_COLOR
			FormatString(buf, "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ",
					buf, level_colors[Level], level_names[Level], File, Line);
			fputs(buf, stderr);
#else
			FormatString(buf, "%s %-5s %s:%d ", buf, level_names[Level], File, Line);
			fputs(buf, stderr);
#endif
		}
		va_start(args, Fmt);
		stbsp_vsprintf(Buffer, Fmt, args);
		//Appends "\n". For special case use. Treat with care.
		if(LogNewLine)
		{
			puts(Buffer);
		}
		else
		{
			fputs(Buffer, stderr);
		}
		va_end(args);
	}

	/* Log to file */
	if (Logfp)
	{
		va_list args;
		if(LogExtra)
		{
			char buf[32];
			buf[strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", lt)] = '\0';
			FormatString(buf, "%s %-5s %s:%d: ", buf, level_names[Level], File, Line);
			fputs(buf, Logfp);
		}
		va_start(args, Fmt);
		stbsp_vsprintf(Buffer, Fmt, args);
		strcat(Buffer, "\n");
		fputs(Buffer, Logfp);
		va_end(args);
		fflush(Logfp);
	}
	Lock = 0;
}

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
	u32 IsExpose;
} linux_wnd;

static linux_wnd Wnd;

void SurfaceCallback(VkSurfaceKHR* Surface)
{
	VkXlibSurfaceCreateInfoKHR SurfaceCI;
	SurfaceCI.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
	SurfaceCI.pNext = NULL;
	SurfaceCI.flags = 0;
	SurfaceCI.dpy = Wnd.Display;
	SurfaceCI.window = Wnd.Window;

	VK_CHECK(vkCreateXlibSurfaceKHR(Instance, &SurfaceCI, NULL, Surface));
}


void ProcessEvents()
{

	XEvent Event;
	while (XPending(Wnd.Display) > 0) 
	{
		//see https://tronche.com/gui/x/xlib/events/structures.html 
		//NOTE(Kyryl): So the issue was that with validation layers enabled when resizing the window
		//too quickly it triggers and forces assert. Without everything works fine. One way to prevent it is
		//to watch for events, which now work, and stop the renderer until resize has finished. But this looks lame and
		//I don't like it.
		XNextEvent(Wnd.Display, &Event);
		switch(Event.type)
		{
			#ifdef TINYENGINE_DEBUG
			#define DbgEvent Debug
			#else
			#define DbgEvent(...)
			#endif
			case KeyPress:
				DbgEvent("KeyPress");
				break;
			case KeyRelease:
				DbgEvent("KeyRelease");
				break;
			case ButtonPress:
				DbgEvent("ButtonPress");
				break;
			case ButtonRelease:
				DbgEvent("ButtonRelease");
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
				break;
		}
	}
}

int main(int argc, char** argv)
{
	FILE* File = fopen("./log.txt","w");
	LogSetfp(File);

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
	if(!InitVulkan(&ProcAddr, ArrayCount(RequiredExtensions), RequiredExtensions))
	{
		Fatal("Failed to initialize vulkan runtime!");
		exit(1);
	}

	XSelectInput(Wnd.Display, Wnd.Window, 
			ExposureMask | KeyPressMask | KeyReleaseMask | PointerMotionMask |
			ButtonPressMask | ButtonReleaseMask  | StructureNotifyMask | ResizeRequest |
			ButtonPress | ButtonRelease);

	XMapWindow(Wnd.Display, Wnd.Window);

	// Set window title
	XStoreName(Wnd.Display, Wnd.Window, "TinyEngine");

	//Maybe some day events will be threaded? 
	//pthread_t Ithread;
	//ASSERT(!pthread_create(&Ithread, NULL, &EventThread, NULL), "pthread: EventThread failed.");

	while (1) 
	{
		ProcessEvents();

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

