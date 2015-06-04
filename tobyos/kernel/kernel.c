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
	printf("Hello, TobyOS kernel World!\n");
	
	uint16_t k = 5 / 0;
	uint16_t z = k - 1;
}
