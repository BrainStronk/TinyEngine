#ifndef LOG_H
#define LOG_H

#ifndef STB_SPRINTF_IMPLEMENTATION
#define STB_SPRINTF_IMPLEMENTATION
#endif

#include <time.h>
#include "stb_sprintf.h"

b32 LogNewLine = true;
b32 LogExtra = true;

typedef void (*log_LockFn)(void *udata, int lock);

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL, T_LOG };

//(Kyryl): This log does not care about debug level set.
//useful to do fast print debugging, p(...) is nice and short
//do not leave hanging in production code though.
#define p(...) log_log(T_LOG, __FILE__, __LINE__, __VA_ARGS__)

#ifdef TINYENGINE_DEBUG

#define Trace(...) log_log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define Debug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define Info(...)  log_log(LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define Warn(...)  log_log(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define Error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define Fatal(...) log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

#else

#define Trace(...)
#define Debug(...)
#define Info(...)
#define Warn(...)
#define Error(...)
#define Fatal(...)

#endif

void log_set_udata(void *udata);
void log_set_lock(log_LockFn fn);
void log_set_fp(FILE *fp);
void log_set_level(int level);
void log_set_quiet(int enable);

void log_log(int level, const char *file, int line, const char *fmt, ...);
static struct
{
	void *udata;
	log_LockFn lock;
	FILE *fp;
	int level;
	int quiet;
} L;

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

static void lock(void)
{
	if (L.lock)
	{
		L.lock(L.udata, 1);
	}
}


static void unlock(void)
{
	if (L.lock)
	{
		L.lock(L.udata, 0);
	}
}


void log_set_udata(void *udata)
{
	L.udata = udata;
}


void log_set_lock(log_LockFn fn)
{
	L.lock = fn;
}


void log_set_fp(FILE *fp)
{
	L.fp = fp;
}


void log_set_level(int level)
{
	L.level = level;
}


void log_set_quiet(int enable)
{
	L.quiet = enable ? 1 : 0;
}

void FormatString(char* Buf, char* Str, ...)
{
	va_list Args;
	va_start(Args, Str);
	stbsp_vsprintf(Buf, Str, Args);
	va_end(Args);
}

void log_log(int level, const char *file, int line, const char *fmt, ...)
{
	if (level < L.level)
	{
		return;
	}

	/* Acquire lock */
	lock();

	char Buffer[1024];

	/* Get current time */
	time_t t = time(NULL);
	struct tm *lt = localtime(&t);

	/* Log to terminal */
	if (!L.quiet)
	{
		va_list args;
		if(LogExtra)
		{
			char buf[16];
			buf[strftime(buf, sizeof(buf), "%H:%M:%S", lt)] = '\0';
#ifdef LOG_USE_COLOR
			FormatString(buf, "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ",
					buf, level_colors[level], level_names[level], file, line);
			fputs(buf, stderr);
#else
			FormatString(buf, "%s %-5s %s:%d ", buf, level_names[level], file, line);
			fputs(buf, stderr);
#endif
		}
		va_start(args, fmt);
		stbsp_vsprintf(Buffer, fmt, args);
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
	if (L.fp)
	{
		va_list args;
		if(LogExtra)
		{
			char buf[32];
			buf[strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", lt)] = '\0';
			FormatString(buf, "%s %-5s %s:%d: ", buf, level_names[level], file, line);
			fputs(buf, L.fp);
		}
		va_start(args, fmt);
		stbsp_vsprintf(Buffer, fmt, args);
		strcat(Buffer, "\n");
		fputs(Buffer, L.fp);
		va_end(args);
		fflush(L.fp);
	}

	/* Release lock */
	unlock();
}

#endif
