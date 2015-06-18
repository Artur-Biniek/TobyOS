#include "io.h"

inline uint8_t
io_inb (uint16_t port)
{
  uint8_t data;
  asm volatile ("inb %w1, %b0" : "=a" (data) : "Nd" (port));
  return data;
}

inline uint16_t
io_inw (uint16_t port)
{
  uint16_t data;
  asm volatile ("inw %w1, %w0" : "=a" (data) : "Nd" (port));
  return data;
}

inline uint32_t
io_ind (uint16_t port)
{ 
  uint32_t data;
  asm volatile ("inl %w1, %0" : "=a" (data) : "Nd" (port));
  return data;
}

inline void
io_outb (uint16_t port, uint8_t data)
{
  asm volatile ("outb %b0, %w1" : : "a" (data), "Nd" (port));
}

inline void
io_outw (uint16_t port, uint16_t data)
{
  asm volatile ("outw %w0, %w1" : : "a" (data), "Nd" (port));
}

inline void
io_outl (uint16_t port, uint32_t data)
{ 
  asm volatile ("outl %0, %w1" : : "a" (data), "Nd" (port));
}
