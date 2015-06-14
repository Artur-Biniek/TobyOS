#ifndef _ARCH_i386_IDT_H
#define _ARCH_i386_IDT_H

#include <stddef.h>

#include "asm.h"

#define IDT_NUM_ENTRIES 256

#define IDT_TASK_GATE 0x5
#define IDT_INTR_GATE 0xE
#define IDT_TRAP_GATE 0xF

typedef struct
{
  uint32_t eax;
  uint32_t ecx;
  uint32_t edx;
  uint32_t ebx;
  uint32_t esp;
  uint32_t ebp;
  uint32_t esi;
  uint32_t edi;
} regs_t;

extern void interrupt_handler_null (void);

void idt_initialize (void);

#endif
