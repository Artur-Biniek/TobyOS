#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>

#if defined (__i386__)
#include "../arch/i386/gdt.h"
#include "../arch/i386/idt.h"
#endif

void kernel_init(void)
{
	terminal_initialize();
	gdt_initialize();
	idt_initialize();
}

void kernel_main(void)
{			
	printf("Hello, TobyOS kernel World!\n");
}
