; Declare constants used for creating a multiboot header.
MBALIGN     equ  1<<0                   ; align loaded modules on page boundaries
MEMINFO     equ  1<<1                   ; provide memory map
FLAGS       equ  MBALIGN | MEMINFO      ; this is the Multiboot 'flag' field
MAGIC       equ  0x1BADB002             ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + FLAGS)        ; checksum of above, to prove we are multiboot

KSTACK_SIZE equ 16384			; kernel stack size
 
	section .multiboot
	align 4
	
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
	
some_mag:
	db 0
 
	section .text
	global _start
	
_start:				
	mov esp, stack_top	
		
	cli
	
	; Initialize the core kernel before running the global constructors.
	extern kernel_init
	call kernel_init	
	
	; Transfer control to the main kernel.
	extern kernel_main
	call kernel_main
	
	mov eax, 12
	idiv byte [some_mag]	
	
	global hang_kernel;
hang_kernel:		
	cli
	hlt 
	jmp hang_kernel		; Hang

	section .bootstrap_stack, nobits
	align 4
	
	
stack_bottom:
	resb KSTACK_SIZE
stack_top:
