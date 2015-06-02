#ifndef _ARCH_i386_ASM_H
#define _ARCH_i386_ASM_H

#include <stdint.h>

void gdt_set(uintptr_t gdt_ptr);
void idt_set(uintptr_t gdt_ptr);

#endif
