#include <kernel/kernel.h>
#include <sys/gccdefs.h>

#include "asm.h"
#include "gdt.h"
#include "idt.h"

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

typedef void interrupt_stub (void);
extern interrupt_stub *interrupt_stubs[IDT_NUM_ENTRIES];

static idt_entry_t idt_entries[IDT_NUM_ENTRIES];

void 
idt_set_gate (uint8_t number, uint16_t segment, uintptr_t base, uint8_t flags)
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
