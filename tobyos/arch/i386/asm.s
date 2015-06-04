;-----------------------------------------------------------------------
; gdt_set - loads Global Descriptor Table
;-----------------------------------------------------------------------
	global gdt_set
gdt_set:
		
	mov eax, [esp + 4]
	lgdt [eax]
	
	jmp 0x08:cs_reload ; "far" jump to reload CS

cs_reload:		
		
	mov eax, 0x10
	mov ds, ax	
	mov es, ax
	mov fs, ax
	mov gs, ax	
	mov ss, ax
	
	ret

	
;-----------------------------------------------------------------------
; idt_set - loads Interrupt Descriptor Table
;-----------------------------------------------------------------------
	global idt_set
idt_set:
		
	mov eax, [esp + 4]
	lidt [eax]	
	
	ret

