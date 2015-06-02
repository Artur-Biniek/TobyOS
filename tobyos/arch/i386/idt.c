#include "idt.h"

#define IDT_NUM_ENTRIES 256

#define IDT_TASK_GATE 0x5
#define IDT_INTR_GATE 0xE
#define IDT_TRAP_GATE 0xF

typedef struct
{
	uint16_t offset_low;
	uint16_t segment;
	uint8_t zero;
	uint8_t flags;
	uint16_t offset_high;
} idt_entry_t;

typedef struct
{
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) idt_ptr_t;

static idt_entry_t idt_entries[IDT_NUM_ENTRIES];

void idt_initialize(void)
{
	idt_entry_t t;
	
	idt_entries[0] = t;
	
	idt_ptr_t idt_ptr ;
	idt_ptr.base = (uintptr_t) &idt_entries;
	idt_ptr.limit = sizeof(idt_entries) - 1;
	
	idt_set((uintptr_t)&idt_ptr);
}
