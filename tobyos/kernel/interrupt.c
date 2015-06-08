#include <kernel/kernel.h>
#include <kernel/interrupt.h>

#include <stdio.h>
#include <debug.h>


void
interrupt_handler (regs_t regs, uint32_t num, uint32_t err)
{ 
  PANIC ("Hey!? UNHANDLED INTERRUPT %x!", err);
}
