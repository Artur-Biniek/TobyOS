#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/kernel.h>
#include <kernel/tty.h>

#include <sys/gccdefs.h>

#include <debug.h>

#if defined (__i386__)
#include "../arch/i386/gdt.h"
#endif

extern void __KERNEL_START (void);
extern void __KERNEL_END (void);

void 
kernel_init (void)
{
  terminal_initialize ();
  gdt_initialize ();

  intr_initialize ();
}

void
kernel_main (void)
{ 
  int i = 0;  

  asm volatile ("int $0x26");
  
  asm volatile ("int $0xF0");
  
  puts("");

  ASSERT(i == 1);
}
