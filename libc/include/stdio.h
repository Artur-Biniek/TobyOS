#ifndef _STDIO_H
#define _STDIO_H

#include <sys/cdefs.h>
#include <sys/gccdefs.h>

#include <stdarg.h>

int printf (const char*, ...) PRINTF_FORMAT(1, 2);
int vprintf (const char *, va_list) PRINTF_FORMAT (1, 0);

int putchar (int);
int puts (const char*);

#endif
