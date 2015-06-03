#ifndef _KERNEL_KERNEL_H
#define _KERNEL_KERNEL_H

extern void hang_kernel(void);
void KPANIC(const char* message);

#endif
