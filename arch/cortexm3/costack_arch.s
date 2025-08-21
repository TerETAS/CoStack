;Costack
;Copyright 2025 TerETAS 
;Released under an MIT license. See LICENSE file. 


    AREA |.text|,CODE,READONLY
    THUMB
    PRESERVE8


    extern cst_coroutine_trampoline ;
	extern ;
	extern ;


COSTACK_PAR_OFS      EQU      20   ;costack_t.par offset
cst_context_switch PROC      
    push    {r3-r11,lr}         ;save context
    str     sp,[r0]             ;save sp
    ldr     sp,[r1]             ;get  new sp
    pop     {r3-r11,lr}         ;get  context 
    mov     r0,r2               ;pass par
    bx      lr                  ;return 
    ENDP



cst_coroutine_trampoline_wrapper PROC
    bx   cst_coroutine_trampoline    ;keep r0 and go to cst_coroutine_trampoline
    b    .                           ;unreachable

    ENDP







