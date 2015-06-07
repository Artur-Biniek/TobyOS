#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/kernel.h>
#include <kernel/tty.h>

#if defined (__i386__)
#include "../arch/i386/gdt.h"
#include "../arch/i386/idt.h"
#endif

extern void __KERNEL_START(void);
extern void __KERNEL_END(void);

void KPANIC(const char* message)
{
	printf(message);
	hang_kernel();
}

void kernel_init(void)
{
	terminal_initialize();
	gdt_initialize();
	idt_initialize();
}

void kernel_main(void)
{	
	int i = 0;
	for (; i < 30; i++) 
    {		
      printf("Decimal: %d, Hex: %x\n", i, i); 
    }
}
