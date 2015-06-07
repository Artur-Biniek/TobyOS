#include <stdint.h>
#include <sys/gccdefs.h>

#include "gdt.h"

#define GDT_NUM_ENTRIES 3
#define GDT_FLAGS       0xC0

typedef struct 
{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_high;
} gdt_entry_t;

typedef struct
{
	uint16_t limit;
	uint32_t base;
} PACKED gdt_ptr_t;

static gdt_entry_t gdt_entries[GDT_NUM_ENTRIES];

static void set_gate(uint8_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags)
{
	gdt_entry_t* entry = (gdt_entry_t*) &gdt_entries[index];
	
	entry->base_low = base & 0xFFFF;
	entry->base_middle = (base >> 16) & 0xFF;
	entry->base_high = (base >> 24) & 0xFF;
	
	entry->limit_low = limit & 0xFFFF;
	entry->granularity = ((limit >> 16) & 0x0F) | (flags & 0xF0);
	
	entry->access = access;
}

void gdt_initialize(void)
{
	set_gate(0, 0, 0, 0, 0);
	set_gate(1, 0, 0xFFFFFFFF, 0x9A, GDT_FLAGS);
	set_gate(2, 0, 0xFFFFFFFF, 0x92, GDT_FLAGS);
	
	gdt_ptr_t gdt_ptr;
	
	gdt_ptr.limit = sizeof(gdt_entry_t) * GDT_NUM_ENTRIES - 1;
	gdt_ptr.base = (uintptr_t) &gdt_entries;
	
	gdt_set((uintptr_t) &gdt_ptr);
}
