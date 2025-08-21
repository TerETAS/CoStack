//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __COSTACK_ARCH_H__
#define __COSTACK_ARCH_H__
#include "stdint.h"
#include "../../costack.h"

typedef struct cst_arch_save_t
{   
    uint32_t  r3_r11[9];  //r3 is a pad
    uint32_t  lr; 
}cst_arch_save_t;


void cst_coroutine_trampoline_wrapper(void);

static void* cst_init_stack_fill(void* sp_top){
    void* cur_sp = sp_top;

    cur_sp-=9;
    ((uint32_t*)cur_sp)[9]=cst_coroutine_trampoline_wrapper;
   
    return cur_sp;
}







#endif

