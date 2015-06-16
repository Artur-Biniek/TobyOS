#ifndef _KERNEL_INTERRUPT_H
#define _KERNEL_INTERRUPT_H

#include <stdbool.h>

#include "../arch/i386/idt.h"

enum intr_status 
  {
    INTR_OFF, 
    INTR_ON 
  };
  
typedef struct
  {
    uint32_t edi; 
    uint32_t esi; 
    uint32_t ebp;
    uint32_t esp_ignored;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
  } intr_frame_t;

typedef void intr_handler_t (intr_frame_t *);
  
enum intr_status intr_get_status (void);
enum intr_status intr_set_status (enum intr_status);

enum intr_status intr_enable (void);
enum intr_status intr_disable (void);

bool intr_context (void);

void intr_register_ext (uint8_t num, intr_handler_t *, const char *name);
void intr_register_int (uint8_t num, int dpl, enum intr_status,
                        intr_handler_t *, const char *name);
                        
void intr_initialize (void);

#define INTR_SYS_CALL_NUM 0x26

#endif

