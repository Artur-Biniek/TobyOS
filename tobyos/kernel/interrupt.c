#include <kernel/kernel.h>
#include <kernel/interrupt.h>

#include <stdio.h>


void interrupt_handler(regs_t regs, uint32_t num, uint32_t err)
{
	printf("int %d.", num);
	KPANIC("Hey!?");	
}
