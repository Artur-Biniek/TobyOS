#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

int 
printf (const char* format, ...)
{	
  int written = 0;
  
  va_list argp;
  
  va_start (argp, format);	
  written = vprintf (format, argp);
  va_end (argp);
	
  return written;
}
