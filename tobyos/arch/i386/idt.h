#ifndef _ARCH_i386_IDT_H
#define _ARCH_i386_IDT_H

#include <stdint.h>
#include <stddef.h>

#define IDT_NUM_ENTRIES 256

#define IDT_TASK_GATE 0x5
#define IDT_INTR_GATE 0xE
#define IDT_TRAP_GATE 0xF

void idt_set_gate (uint8_t number, uint16_t segment, uintptr_t base, uint8_t flags);
void idt_initialize (void);

#endif
