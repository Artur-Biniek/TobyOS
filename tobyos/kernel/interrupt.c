#include <kernel/kernel.h>
#include <kernel/interrupt.h>

void interrupt_handler(void)
{
	KPANIC("There's now way to go now form this interrupt..");
}
