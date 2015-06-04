%macro interrupt_no_error 1
global interrupt_handler_%1
interrupt_handler_%1:
	push 0
	push %1
	jmp interrupt_handler_common
%endmacro

%macro interrupt_error_code 1
global interrupt_handler_%1
interrupt_handler_%1:
	; [esp] = error code pushed by cpu
	push %1
	jmp interrupt_handler_common
%endmacro

global interrupt_handler_null
interrupt_handler_null:
	iret
	
interrupt_handler_common:
	extern interrupt_handler

	cli
	
	push eax
	push ecx
	push edx
	push ebx
	push esp
	push ebp
	push esi
	push edi
	
	; TODO: might be worth storing CR0 here in case of page faults..
	
	call interrupt_handler	
	
	pop edi
	pop esi
	pop ebp
	add esp, 4	; Esp may not be defined, don't bother to pop.
	pop ebx
	pop edx
	pop ecx
	pop eax
	
	add esp, 8	; Remove int_no and err_code	
	
	iret;
	

interrupt_no_error 	0	; Divide Error
interrupt_no_error 	1	; Debug Exception
interrupt_no_error 	2	; NMI Interrupt
interrupt_no_error 	3	; Breakpoint
interrupt_no_error 	4	; Overflow
interrupt_no_error 	5	; BOUND Range Exceeded
interrupt_no_error 	6	; Invalid Opcode (Undefined Opcode)
interrupt_no_error 	7	; Device Not Available (No Math Coprocessor)
interrupt_error_code 	8	; Double Fault
interrupt_no_error	9	; Coprocessor Segment Overrun (reserved)
interrupt_error_code	10	; Invalid TSS
interrupt_error_code	11	; Segment Not Present
interrupt_error_code	12	; Stack-Segment Fault
interrupt_error_code	13	; General Protection
interrupt_error_code	14	; Page Fault
interrupt_no_error	15	; (Intel reserved. Do not use.)
interrupt_no_error	16	; x87 FPU Floating-Point Error (Math Fault)
interrupt_error_code	17	; Alignment Check
interrupt_no_error	18	; Machine Check
interrupt_no_error	19	; SIMD Floating-Point Exception
interrupt_no_error	20	; Virtualization Exception

interrupt_no_error	21	; Intel reserved. Do not use.
interrupt_no_error	22	; Intel reserved. Do not use.
interrupt_no_error	23	; Intel reserved. Do not use.
interrupt_no_error	24	; Intel reserved. Do not use.
interrupt_no_error	25	; Intel reserved. Do not use.
interrupt_no_error	26	; Intel reserved. Do not use.
interrupt_no_error	27	; Intel reserved. Do not use.
interrupt_no_error	28	; Intel reserved. Do not use.
interrupt_no_error	29	; Intel reserved. Do not use.
interrupt_no_error	30	; Intel reserved. Do not use.
interrupt_no_error	31	; Intel reserved. Do not use.

interrupt_no_error	38	; SYSTEM CALL (int 0x26)




