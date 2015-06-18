#ifndef _ARCH_i386_GDT_H
#define _ARCH_i386_GDT_H

#include <stddef.h>

#include "asm.h"

#define GDT_NLSEG 0x00
#define GDT_KCSEG 0x08
#define GDT_KDSEG 0x10
#define GDT_UCSEG (0x18 & 0x03)
#define GDT_UDSEG (0x20 & 0x03)
// #define GDT_TSS   0x28

#define GDT_NUM_ENTRIES  5

void gdt_initialize(void);

#endif
