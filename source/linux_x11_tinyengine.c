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

//THREADING LIBRARY

//NOTE(Kyryl): 
//Original author 2016, Mathias Brossard <mathias@brossard.org>.
//This is custom modified build. Overall has pretty nice leap into pthreads. 

 
 /**
 * Increase this constants at your own risk
 * Large values might slow down your system
 */
#define MAX_THREADS 64
#define MAX_QUEUE 65536

typedef struct threadpool_t threadpool_t;

typedef enum {
    threadpool_invalid        = -1,
    threadpool_lock_failure   = -2,
    threadpool_queue_full     = -3,
    threadpool_shutdown       = -4,
    threadpool_thread_failure = -5
} threadpool_error_t;

typedef enum {
    threadpool_graceful       = 1
} threadpool_destroy_flags_t;


typedef enum {
    immediate_shutdown = 1,
    graceful_shutdown  = 2
} threadpool_shutdown_t;

/**
 *  @struct threadpool_task
 *  @brief the work struct
 *
 *  @var function Pointer to the function that will perform the task.
 *  @var argument Argument to be passed to the function.
 */

typedef struct {
    void (*function)(void *);
    void *argument;
} threadpool_task_t;

/**
 *  @struct threadpool
 *  @brief The threadpool struct
 *
 *  @var notify       Condition variable to notify worker threads.
 *  @var threads      Array containing worker threads ID.
 *  @var thread_count Number of threads
 *  @var queue        Array containing the task queue.
 *  @var queue_size   Size of the task queue.
 *  @var head         Index of the first element.
 *  @var tail         Index of the next element.
 *  @var count        Number of pending tasks
 *  @var shutdown     Flag indicating if the pool is shutting down
 *  @var started      Number of started threads
 */
typedef struct threadpool_t {
  pthread_mutex_t lock;
  pthread_cond_t notify;
  pthread_t *threads;
  threadpool_task_t *queue;
  int thread_count;
  int queue_size;
  int head;
  int tail;
  int count;
  int shutdown;
  int started;
}threadpool_t;

//FUNCTIONS FORWARD DECL  
threadpool_t *threadpool_create(int thread_count, int queue_size);
int threadpool_add(threadpool_t *pool, void (*routine)(void *),
                   void *arg);
int threadpool_destroy(threadpool_t *pool, int flags);
void *threadpool_thread(void *threadpool);
int threadpool_free(threadpool_t *pool);

/**
 * @function threadpool_create
 * @brief Creates a threadpool_t object.
 * @param thread_count Number of worker threads.
 * @param queue_size   Size of the queue.
 * @param flags        Unused parameter.
 * @return a newly created thread pool or NULL
 */
threadpool_t *threadpool_create(int thread_count, int queue_size)
{
    threadpool_t *pool;
    int i;

    if(thread_count <= 0 || thread_count > MAX_THREADS || queue_size <= 0 || queue_size > MAX_QUEUE) {
        return NULL;
    }

    if((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL) {
        goto err;
    }

    /* Initialize */
    pool->thread_count = 0;
    pool->queue_size = queue_size;
    pool->head = pool->tail = pool->count = 0;
    pool->shutdown = pool->started = 0;

    /* Allocate thread and task queue */
    pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
    pool->queue = (threadpool_task_t *)malloc
        (sizeof(threadpool_task_t) * queue_size);

    /* Initialize mutex and conditional variable first */
    if((pthread_mutex_init(&(pool->lock), NULL) != 0) ||
       (pthread_cond_init(&(pool->notify), NULL) != 0) ||
       (pool->threads == NULL) ||
       (pool->queue == NULL)) {
        goto err;
    }

    /* Start worker threads */
    for(i = 0; i < thread_count; i++) {
        if(pthread_create(&(pool->threads[i]), NULL,
                          threadpool_thread, (void*)pool) != 0) {
            threadpool_destroy(pool, 0);
            return NULL;
        }
        pool->thread_count++;
        pool->started++;
    }

    return pool;

 err:
    if(pool) {
        threadpool_free(pool);
    }
    return NULL;
}

/**
 * @function threadpool_add
 * @brief add a new task in the queue of a thread pool
 * @param pool     Thread pool to which add the task.
 * @param function Pointer to the function that will perform the task.
 * @param argument Argument to be passed to the function.
 * @return 0 if all goes well, negative values in case of error (@see
 * threadpool_error_t for codes).
 */

//TODO(Kyryl): Add va_args to this if possible.
//flags parameter removed.
int threadpool_add(threadpool_t *pool, void (*function)(void *),
                   void *argument)
{
    int err = 0;
    int next;

    if(pool == NULL || function == NULL) {
        return threadpool_invalid;
    }

    if(pthread_mutex_lock(&(pool->lock)) != 0) {
        return threadpool_lock_failure;
    }

    next = (pool->tail + 1) % pool->queue_size;

    do {
        /* Are we full ? */
        if(pool->count == pool->queue_size) {
            err = threadpool_queue_full;
            break;
        }

        /* Are we shutting down ? */
        if(pool->shutdown) {
            err = threadpool_shutdown;
            break;
        }

        /* Add task to queue */
        pool->queue[pool->tail].function = function;
        pool->queue[pool->tail].argument = argument;
        pool->tail = next;
        pool->count += 1;

        /* pthread_cond_broadcast */
        if(pthread_cond_signal(&(pool->notify)) != 0) {
            err = threadpool_lock_failure;
            break;
        }
    } while(0);

    if(pthread_mutex_unlock(&pool->lock) != 0) {
        err = threadpool_lock_failure;
    }

    return err;
}

/**
 * @function threadpool_destroy
 * @brief Stops and destroys a thread pool.
 * @param pool  Thread pool to destroy.
 * @param flags Flags for shutdown
 *
 * Known values for flags are 0 (default) and threadpool_graceful in
 * which case the thread pool doesn't accept any new tasks but
 * processes all pending tasks before shutdown.
 */
int threadpool_destroy(threadpool_t *pool, int flags)
{
    int i, err = 0;

    if(pool == NULL) {
        return threadpool_invalid;
    }

    if(pthread_mutex_lock(&(pool->lock)) != 0) {
        return threadpool_lock_failure;
    }

    do {
        /* Already shutting down */
        if(pool->shutdown) {
            err = threadpool_shutdown;
            break;
        }

        pool->shutdown = (flags & threadpool_graceful) ?
            graceful_shutdown : immediate_shutdown;

        /* Wake up all worker threads */
        if((pthread_cond_broadcast(&(pool->notify)) != 0) ||
           (pthread_mutex_unlock(&(pool->lock)) != 0)) {
            err = threadpool_lock_failure;
            break;
        }

        /* Join all worker thread */
        for(i = 0; i < pool->thread_count; i++) {
            if(pthread_join(pool->threads[i], NULL) != 0) {
                err = threadpool_thread_failure;
            }
        }
    } while(0);

    /* Only if everything went well do we deallocate the pool */
    if(!err) {
        threadpool_free(pool);
    }
    return err;
}

int threadpool_free(threadpool_t *pool)
{
    if(pool == NULL || pool->started > 0) {
        return -1;
    }

    /* Did we manage to allocate ? */
    if(pool->threads) {
        free(pool->threads);
        free(pool->queue);
 
        /* Because we allocate pool->threads after initializing the
           mutex and condition variable, we're sure they're
           initialized. Let's lock the mutex just in case. */
        pthread_mutex_lock(&(pool->lock));
        pthread_mutex_destroy(&(pool->lock));
        pthread_cond_destroy(&(pool->notify));
    }
    free(pool);    
    return 0;
}

void *threadpool_thread(void *threadpool)
{
    threadpool_t *pool = (threadpool_t *)threadpool;
    threadpool_task_t task;

    for(;;) {
        /* Lock must be taken to wait on conditional variable */
        pthread_mutex_lock(&(pool->lock));

        /* Wait on condition variable, check for spurious wakeups.
           When returning from pthread_cond_wait(), we own the lock. */
        while((pool->count == 0) && (!pool->shutdown)) {
            pthread_cond_wait(&(pool->notify), &(pool->lock));
        }

        if((pool->shutdown == immediate_shutdown) ||
           ((pool->shutdown == graceful_shutdown) &&
            (pool->count == 0))) {
            break;
        }

        /* Grab our task */
        task.function = pool->queue[pool->head].function;
        task.argument = pool->queue[pool->head].argument;
        pool->head = (pool->head + 1) % pool->queue_size;
        pool->count -= 1;

        /* Unlock */
        pthread_mutex_unlock(&(pool->lock));

        /* Get to work */
        (*(task.function))(task.argument);
    }

    pool->started--;

    pthread_mutex_unlock(&(pool->lock));
    pthread_exit(NULL);
    return(NULL);
}
//----------------------THREADING LIBRARY


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
threadpool_t *ThreadPool[5];
pthread_mutex_t PthreadLock;

void SurfaceCallback(VkSurfaceKHR* Surface)
{
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

void EventThread()
{

	//WTF(Kyryl): Okay what is this, the mask parameter does not work for anything except keyboard?
	//if(XCheckWindowEvent(Wnd.Display, Wnd.Window, KeyPressMask | KeyReleaseMask | PointerMotionMask, &Event))
	//{};
	XEvent Event;
	while (1) 
	{
		//see https://tronche.com/gui/x/xlib/events/structures.html 
		//NOTE(Kyryl): This function is not thread safe!
		XWindowAttributes Attr;
		XGetWindowAttributes(Wnd.Display, Wnd.Window, &Attr);
		Wnd.Width = Attr.width;
		Wnd.Height = Attr.height;
		SetSizeOfSwapchainImages(Wnd.Width, Wnd.Height);

		XNextEvent(Wnd.Display, &Event);
		switch(Event.type)
		{
			//WTF idk what to do, some of these events are not even triggering on my system :(
			//Probably has to do with Attr bitmask set during window creation.
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
		}
	}
}

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

	pthread_mutex_init(&PthreadLock, NULL);
	ThreadPool[0] = threadpool_create(1, 1024);
	ASSERT(threadpool_add(ThreadPool[0], &EventThread, NULL) == 0, "Failed threadpool_add");

	while (1) 
	{
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

