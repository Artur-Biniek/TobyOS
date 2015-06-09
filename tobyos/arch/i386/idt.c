#include <kernel/kernel.h>
#include <sys/gccdefs.h>

#include "idt.h"

#define IDT_NUM_ENTRIES 256

#define IDT_TASK_GATE 0x5
#define IDT_INTR_GATE 0xE
#define IDT_TRAP_GATE 0xF

typedef struct
{
  uint16_t base_low;
  uint16_t segment;
  uint8_t zero;
  uint8_t flags;
  uint16_t base_high;
} idt_entry_t;

typedef struct
{
  uint16_t limit;
  uint32_t base;
} PACKED idt_ptr_t;

typedef void intrerrupt_stub (void);
extern intrerrupt_stub *interrupt_stubs[IDT_NUM_ENTRIES];

static idt_entry_t idt_entries[IDT_NUM_ENTRIES];

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

const char * 
idt_get_std_error (uint8_t err_no)
{
  return exception_names[err_no];
}

static void 
idt_set_gate (uint16_t number, uint16_t segment, uintptr_t base, uint8_t flags)
{
  idt_entry_t* entry = & idt_entries[number];
  
  entry->segment = segment;
  entry->base_low = base & 0xFFFF;
  entry->base_high = (base >> 16) & 0xFFFF;
  entry->zero = 0;
  entry->flags = flags;
}

void
idt_initialize (void)
{
  int i;
  
  for (i = 0; i < IDT_NUM_ENTRIES; i++)
    {     
      idt_set_gate (i, 0x08, (uintptr_t) interrupt_stubs[i], 0x8E);
    }
  
  idt_ptr_t idt_ptr;
  
  idt_ptr.base = (uintptr_t) &idt_entries;
  idt_ptr.limit = sizeof(idt_entries) - 1;
  
  idt_set ((uintptr_t)&idt_ptr);
}
