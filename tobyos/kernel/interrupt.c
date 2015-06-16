#include <kernel/kernel.h>
#include <kernel/interrupt.h>

#if defined (__i386__)
#include "../arch/i386/idt.h"
#include "../arch/i386/asm.h"
#endif

#include <stdint.h>
#include <stdio.h>
#include <debug.h>

#define EXCEPT_NUM_ENTRIES 20
#define INTR_FLAG_IF      0x00000200 
#define INTR_EXTERN_START 0x30
#define INTR_EXTERN_END   0x3f

static intr_handler_t *intr_handlers[IDT_NUM_ENTRIES];
static char* intr_name[IDT_NUM_ENTRIES];

static bool is_in_external_interrupt;

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
unhandled_interrupt (uint8_t num)
{
   PANIC ("UNHANDLED INTERRUPT (%x - %s)!", num, intr_name[num]);
}

bool
intr_context (void)
{
  return is_in_external_interrupt;
}

enum intr_status
intr_get_status (void)
{
  uint32_t flags;

  asm volatile ("pushfl; popl %0" : "=g" (flags));

  return flags & INTR_FLAG_IF ? INTR_ON : INTR_OFF;
}

enum intr_status
intr_set_status (enum intr_status status)
{
  return status == INTR_ON ? intr_enable () : intr_disable ();
}

enum intr_status
intr_enable (void) 
{
  enum intr_status old_status = intr_get_status ();
  
  ASSERT (!intr_context ());

  asm volatile ("sti");

  return old_status;
}

enum intr_status
intr_disable (void) 
{
  enum intr_status old_status = intr_get_status ();

  asm volatile ("cli" : : : "memory");

  return old_status;
}

void
interrupt_handler (intr_frame_t frame, uint8_t num, uint32_t err)
{    
  
  (*intr_handlers[num]) (num);
}

void
intr_initialize (void)
{
  int i;

  idt_initialize ();
  
  for (i = 0; i < EXCEPT_NUM_ENTRIES; i++)
    {
      intr_name[i] = exception_names[i];
    }
  
  for (i = EXCEPT_NUM_ENTRIES; i < IDT_NUM_ENTRIES; i++)
    {
      intr_name[i] = "UNKNOWN";
    }    
   
  for (i = 0; i < IDT_NUM_ENTRIES; i++)
    {
      intr_handlers[i] = &unhandled_interrupt;
    }
          
   intr_name[INTR_SYS_CALL_NUM] = "SYSTEM CALL";
   
   intr_handlers[INTR_SYS_CALL_NUM] = &system_call;
}

