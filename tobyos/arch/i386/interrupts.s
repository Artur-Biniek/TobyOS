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
	iret;
	

interrupt_no_error 0
interrupt_no_error 1
interrupt_no_error 2
interrupt_no_error 3
interrupt_no_error 4
interrupt_no_error 5
interrupt_no_error 6
interrupt_no_error 7
interrupt_no_error 8
