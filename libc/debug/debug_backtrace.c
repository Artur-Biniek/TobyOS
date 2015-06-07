#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <debug.h>

void
debug_backtrace (void) 
{
  void **frame;
  
  printf ("Call stack: %p", __builtin_return_address (0));
  
  for (frame = __builtin_frame_address (1);
       (uintptr_t) frame >= 0x1000 && frame[0] != NULL;
       frame = frame[0])
    {
      printf (" %p", frame[1]);
    }
    
  printf (".\n");
}
