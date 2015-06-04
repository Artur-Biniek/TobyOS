#include <kernel/kernel.h>
#include <kernel/interrupt.h>


void interrupt_handler(regs_t regs, uint32_t num, uint32_t err)
{
	KPANIC("Hey!?");	
}
