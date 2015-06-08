#include <stdio.h>
#include <stdarg.h>
#include <debug.h>

#include <kernel/kernel.h>

void
debug_panic (const char *file, int line, const char *function,
             const char *message, ...)
{
  va_list argp;
  
  va_start (argp, message);
  
  printf ("KERNEL PANIC: (%s) %s:%d.\n", function, file, line);
  vprintf (message, argp);
  
  va_end (argp);
  
  printf ("\n");
  
  debug_backtrace ();
  
  hang_kernel ();
}
