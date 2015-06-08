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
#include "../arch/i386/idt.h"
#endif

extern void __KERNEL_START (void);
extern void __KERNEL_END (void);

void 
kernel_init (void)
{
	terminal_initialize ();
	gdt_initialize ();
	idt_initialize();
}

void NO_INLINE 
blah_inner (int x)  
{
  asm ("");
  PANIC ("Kurcze.. %d", x);
  asm ("");
}

void NO_INLINE
blah (void)
{
  asm ("");
  blah_inner (5);
  asm ("");
}

void
kernel_main (void)
{	
	int i = 0;

	for (; i < 30; i++) 
    {		
      printf("Decimal: %d, Hex: %x\n", i, i); 
    }
    
  ASSERT(i == 1);
    
  blah ();
}
