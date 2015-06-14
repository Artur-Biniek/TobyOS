%macro interrupt_no_error 1

[section .code]
interrupt_handler_%1:
        push 0
        push %1
        jmp interrupt_handler_common
[section .data]
        dd interrupt_handler_%1

%endmacro

%macro interrupt_error_code 1

[section .code]
interrupt_handler_%1:
        ; [esp] = error code pushed by cpu
        push %1
        jmp interrupt_handler_common
[section .data]
        dd interrupt_handler_%1

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
        add esp, 4  ; Esp may not be defined, don't bother to pop.
        pop ebx
        pop edx
        pop ecx
        pop eax
  
        add esp, 8  ; Remove int_no and err_code  
  
        iret;
  
section .data
global interrupt_stubs
interrupt_stubs:

interrupt_no_error    0 ; Divide Error
interrupt_no_error    1 ; Debug Exception
interrupt_no_error    2 ; NMI Interrupt
interrupt_no_error    3 ; Breakpoint
interrupt_no_error    4 ; Overflow
interrupt_no_error    5 ; BOUND Range Exceeded
interrupt_no_error    6 ; Invalid Opcode (Undefined Opcode)
interrupt_no_error    7 ; Device Not Available (No Math Coprocessor)
interrupt_error_code  8 ; Double Fault
interrupt_no_error    9 ; Coprocessor Segment Overrun (reserved)

interrupt_error_code  10  ; Invalid TSS
interrupt_error_code  11  ; Segment Not Present
interrupt_error_code  12  ; Stack-Segment Fault
interrupt_error_code  13  ; General Protection
interrupt_error_code  14  ; Page Fault
interrupt_no_error    15  ; (Intel reserved. Do not use.)
interrupt_no_error    16  ; x87 FPU Floating-Point Error (Math Fault)
interrupt_error_code  17  ; Alignment Check
interrupt_no_error    18  ; Machine Check
interrupt_no_error    19  ; SIMD Floating-Point Exception
interrupt_no_error    20  ; Virtualization Exception

interrupt_no_error  21  ; Intel reserved. Do not use.
interrupt_no_error  22  ; Intel reserved. Do not use.
interrupt_no_error  23  ; Intel reserved. Do not use.
interrupt_no_error  24  ; Intel reserved. Do not use.
interrupt_no_error  25  ; Intel reserved. Do not use.
interrupt_no_error  26  ; Intel reserved. Do not use.
interrupt_no_error  27  ; Intel reserved. Do not use.
interrupt_no_error  28  ; Intel reserved. Do not use.
interrupt_no_error  29  ; Intel reserved. Do not use.
interrupt_no_error  30  ; Intel reserved. Do not use.

interrupt_no_error  31  ; Intel reserved. Do not use.
interrupt_no_error  32
interrupt_no_error  33
interrupt_no_error  34
interrupt_no_error  35
interrupt_no_error  36
interrupt_no_error  37
interrupt_no_error  38  ; SYSTEM CALL (int 0x26)
interrupt_no_error  39

interrupt_no_error  40
interrupt_no_error  41
interrupt_no_error  42
interrupt_no_error  43
interrupt_no_error  44
interrupt_no_error  45
interrupt_no_error  46
interrupt_no_error  47
interrupt_no_error  48
interrupt_no_error  49

interrupt_no_error  50
interrupt_no_error  51
interrupt_no_error  52
interrupt_no_error  53
interrupt_no_error  54
interrupt_no_error  55
interrupt_no_error  56
interrupt_no_error  57
interrupt_no_error  58
interrupt_no_error  59

interrupt_no_error  60
interrupt_no_error  61
interrupt_no_error  62
interrupt_no_error  63
interrupt_no_error  64
interrupt_no_error  65
interrupt_no_error  66
interrupt_no_error  67
interrupt_no_error  68
interrupt_no_error  69

interrupt_no_error  70
interrupt_no_error  71
interrupt_no_error  72
interrupt_no_error  73
interrupt_no_error  74
interrupt_no_error  75
interrupt_no_error  76
interrupt_no_error  77
interrupt_no_error  78
interrupt_no_error  79

interrupt_no_error  80
interrupt_no_error  81
interrupt_no_error  82
interrupt_no_error  83
interrupt_no_error  84
interrupt_no_error  85
interrupt_no_error  86
interrupt_no_error  87
interrupt_no_error  88
interrupt_no_error  89

interrupt_no_error  90
interrupt_no_error  91
interrupt_no_error  92
interrupt_no_error  93
interrupt_no_error  94
interrupt_no_error  95
interrupt_no_error  96
interrupt_no_error  97
interrupt_no_error  98
interrupt_no_error  99

interrupt_no_error  100
interrupt_no_error  101
interrupt_no_error  102
interrupt_no_error  103
interrupt_no_error  104
interrupt_no_error  105
interrupt_no_error  106
interrupt_no_error  107
interrupt_no_error  108
interrupt_no_error  109

interrupt_no_error  110
interrupt_no_error  111
interrupt_no_error  112
interrupt_no_error  113
interrupt_no_error  114
interrupt_no_error  115
interrupt_no_error  116
interrupt_no_error  117
interrupt_no_error  118
interrupt_no_error  119

interrupt_no_error  120
interrupt_no_error  121
interrupt_no_error  122
interrupt_no_error  123
interrupt_no_error  124
interrupt_no_error  125
interrupt_no_error  126
interrupt_no_error  127
interrupt_no_error  128
interrupt_no_error  129

interrupt_no_error  130
interrupt_no_error  131
interrupt_no_error  132
interrupt_no_error  133
interrupt_no_error  134
interrupt_no_error  135
interrupt_no_error  136
interrupt_no_error  137
interrupt_no_error  138
interrupt_no_error  139

interrupt_no_error  140
interrupt_no_error  141
interrupt_no_error  142
interrupt_no_error  143
interrupt_no_error  144
interrupt_no_error  145
interrupt_no_error  146
interrupt_no_error  147
interrupt_no_error  148
interrupt_no_error  149

interrupt_no_error  150
interrupt_no_error  151
interrupt_no_error  152
interrupt_no_error  153
interrupt_no_error  154
interrupt_no_error  155
interrupt_no_error  156
interrupt_no_error  157
interrupt_no_error  158
interrupt_no_error  159

interrupt_no_error  160
interrupt_no_error  161
interrupt_no_error  162
interrupt_no_error  163
interrupt_no_error  164
interrupt_no_error  165
interrupt_no_error  166
interrupt_no_error  167
interrupt_no_error  168
interrupt_no_error  169

interrupt_no_error  170
interrupt_no_error  171
interrupt_no_error  172
interrupt_no_error  173
interrupt_no_error  174
interrupt_no_error  175
interrupt_no_error  176
interrupt_no_error  177
interrupt_no_error  178
interrupt_no_error  179

interrupt_no_error  180
interrupt_no_error  181
interrupt_no_error  182
interrupt_no_error  183
interrupt_no_error  184
interrupt_no_error  185
interrupt_no_error  186
interrupt_no_error  187
interrupt_no_error  188
interrupt_no_error  189

interrupt_no_error  190
interrupt_no_error  191
interrupt_no_error  192
interrupt_no_error  193
interrupt_no_error  194
interrupt_no_error  195
interrupt_no_error  196
interrupt_no_error  197
interrupt_no_error  198
interrupt_no_error  199

interrupt_no_error  200
interrupt_no_error  201
interrupt_no_error  202
interrupt_no_error  203
interrupt_no_error  204
interrupt_no_error  205
interrupt_no_error  206
interrupt_no_error  207
interrupt_no_error  208
interrupt_no_error  209

interrupt_no_error  210
interrupt_no_error  211
interrupt_no_error  212
interrupt_no_error  213
interrupt_no_error  214
interrupt_no_error  215
interrupt_no_error  216
interrupt_no_error  217
interrupt_no_error  218
interrupt_no_error  219

interrupt_no_error  220
interrupt_no_error  221
interrupt_no_error  222
interrupt_no_error  223
interrupt_no_error  224
interrupt_no_error  225
interrupt_no_error  226
interrupt_no_error  227
interrupt_no_error  228
interrupt_no_error  229

interrupt_no_error  230
interrupt_no_error  231
interrupt_no_error  232
interrupt_no_error  233
interrupt_no_error  234
interrupt_no_error  235
interrupt_no_error  236
interrupt_no_error  237
interrupt_no_error  238
interrupt_no_error  239

interrupt_no_error  240
interrupt_no_error  241
interrupt_no_error  242
interrupt_no_error  243
interrupt_no_error  244
interrupt_no_error  245
interrupt_no_error  246
interrupt_no_error  247
interrupt_no_error  248
interrupt_no_error  249

interrupt_no_error  250
interrupt_no_error  251
interrupt_no_error  252
interrupt_no_error  253
interrupt_no_error  254
interrupt_no_error  255
