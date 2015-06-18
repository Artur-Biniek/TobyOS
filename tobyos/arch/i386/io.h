#include <stdint.h>
#include <sys/gccdefs.h>

uint8_t  INLINE io_inb (uint16_t port);
uint16_t INLINE io_inw (uint16_t port);
uint32_t INLINE io_ind (uint16_t port);
void INLINE io_outb (uint16_t port, uint8_t data);
void INLINE io_outw (uint16_t port, uint16_t data);
void INLINE io_outl (uint16_t port, uint32_t data);
