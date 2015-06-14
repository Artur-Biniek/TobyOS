#include <kernel/kernel.h>
#include <kernel/interrupt.h>

#include "../arch/i386/idt.h"

#include <stdio.h>
#include <debug.h>

#define EXCEPT_NUM_ENTRIES 20

typedef void intr_handler_t (size_t);

static intr_handler_t *intr_handlers[IDT_NUM_ENTRIES];
static char* intr_name[IDT_NUM_ENTRIES];

static char* exception_names[] =
{
  "Divide by zero",              /* 0, 0x0 */
  "Debug",                       /* 1, 0x1 */
  "Non maskable interrupt",      /* 2, 0x2 */
  "Breakpoint",                  /* 3, 0x3 */
  "Into detected overflow",      /* 4, 0x4 */
  "Out of bounds",               /* 5, 0x5 */
  "Invalid opcode",              /* 6, 0x6 */
  "No coprocessor",              /* 7, 0x7 */
  "Double fault",                /* 8, 0x8 */
  "Coprocessor segment overrun", /* 9, 0x9 */
  "Bad TSS",                     /* 10, 0xA */
  "Segment not present",         /* 11, 0xB */
  "Stack fault",                 /* 12, 0xC */
  "General protection fault",    /* 13, 0xD */
  "Page fault",                  /* 14, 0xE */
  "Unknown interrupt",           /* 15, 0xF */
  "Coprocessor fault",           /* 16, 0x10 */
  "Alignment check",             /* 17, 0x11 */
  "Machine check",               /* 18, 0x12 */
  "SIMD Floating-Point",         /* 19, 0x13 */
};

static void
system_call (size_t number)
{
  printf ("System call.");
}

static void NO_RETURN
unhandled_interrupt (size_t num)
{
   PANIC ("UNHANDLED INTERRUPT (%x - %s)!", num, intr_name[num]);
}

void
interrupt_handler (regs_t regs, size_t num, uint32_t err)
{    
  (*intr_handlers[num]) (num);
}

void
intr_initialize (void)
{
  int i;
  
  for (i = 0; i < EXCEPT_NUM_ENTRIES; i++)
    {
      intr_name[i] = exception_names[i];
    }
  
  for (i = EXCEPT_NUM_ENTRIES; i < IDT_NUM_ENTRIES; i++)
    {
      intr_name[i] = "UNKNOWN";
    }    
   
  for (i = 0; i < EXCEPT_NUM_ENTRIES; i++)
    {
      intr_handlers[i] = &unhandled_interrupt;
    }
          
   intr_name[INTR_SYS_CALL_NUM] = "SYSTEM CALL";
   
   intr_handlers[INTR_SYS_CALL_NUM] = &system_call;
}

