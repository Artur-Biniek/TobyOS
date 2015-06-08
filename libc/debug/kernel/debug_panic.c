#include <stdio.h>
#include <debug.h>

void
debug_panic (const char *file, int line, const char *function,
             const char *message, ...)
{
  printf("PANNNNNIC! %s:%d @%s", file, line, function);
  
  debug_backtrace();
  
  while (1)
    {
      ;
    }
}
