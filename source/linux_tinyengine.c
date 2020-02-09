#define LINUX_LEAN_AND_MEAN

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinyengine_types.h"

/*
To avoid naming conflicts and ability to create more than 1 window -
this is a struct.
*/
typedef struct linux_wnd
{ 
	Display* Display;
	Window Window;
	XSetWindowAttributes Attr;
	s32 Screen;
	u32 Width;
	u32 Height; 
	u32 Depth;
	u32 ValueMask;
} linux_wnd;

static linux_wnd Wnd;

int main(int argc, char** argv)
{
   Wnd.Display = XOpenDisplay(getenv("DISPLAY"));
   if (Wnd.Display == NULL)
   {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   Wnd.Screen = XDefaultScreen(Wnd.Display);

   Wnd.Attr.background_pixel = XBlackPixel(Wnd.Display, Wnd.Screen);
   Wnd.ValueMask |= CWBackPixel;
   Wnd.Depth = DefaultDepth(Wnd.Display, Wnd.Screen);
   /*
      TODO(Kyryl): Wnd.Width && Wnd.Height will be the max extent from vulkan swapchain
      vulkan initialization is performed after window creation to create a vulkan surface.
    */
   Wnd.Width = 640;
   Wnd.Height = 640;
   Wnd.Window = XCreateWindow(Wnd.Display, XRootWindow(Wnd.Display, Wnd.Screen),
		   0, 0, Wnd.Width, Wnd.Height,
		   0, Wnd.Depth, InputOutput,
		   DefaultVisual(Wnd.Display, Wnd.Screen),
		   Wnd.ValueMask, &Wnd.Attr);


   XSelectInput(Wnd.Display, Wnd.Window, ExposureMask | KeyPressMask);
   XMapWindow(Wnd.Display, Wnd.Window);
 
   XEvent Event;
   while (1) 
   {
	   //see https://tronche.com/gui/x/xlib/events/structures.html 
	   XNextEvent(Wnd.Display, &Event);
	   switch(Event.type)
	   {
		   case KeyPress:
			   break;
		   case KeyRelease:
			   break;
		   case ButtonPress:
			   break;
		   case ButtonRelease:
			   break;
		   case MotionNotify:
			   break;
		   case EnterNotify:
			   break;
		   case LeaveNotify:
			   break;
		   case FocusIn:
			   break;
		   case FocusOut:
			   break;
		   case KeymapNotify:
			   break;
		   case Expose:
			   break;
		   case GraphicsExpose:
			   break;
		   case NoExpose:
			   break;
		   case VisibilityNotify:
			   break;
		   case CreateNotify:
			   break;
		   case DestroyNotify:
			   break;
		   case UnmapNotify:
			   break;
		   case MapNotify:
			   break;
		   case MapRequest:
			   break;
		   case ReparentNotify:
			   break;
		   case ConfigureNotify:
			   break;
		   case ConfigureRequest:
			   break;
		   case GravityNotify:
			   break;
	   }
   }
 
   XCloseDisplay(Wnd.Display);
   return 0;
}

