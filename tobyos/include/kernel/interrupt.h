#ifndef _KERNEL_INTERRUPT_H
#define _KERNEL_INTERRUPT_H

#include "../arch/i386/idt.h"

void interrupt_handler(regs_t regs, uint32_t num, uint32_t err);

#endif

