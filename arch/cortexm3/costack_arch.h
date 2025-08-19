//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __COSTACK_ARCH_H__
#define __COSTACK_ARCH_H__
#include "stdint.h"
#include "../../costack.h"

typedef struct csr_arch_save_t
{   
    uint32_t  r4_r11[8];
    uint32_t  lr; 
    uint32_t  pad;
}csr_arch_save_t;


void cst_coroutine_trampoline_wrapper(void);

static void* csr_stack_init(void* sp_top){
    void* cur_sp;

    cur_sp-=9;
    ((uint32_t*)cur_sp)[0]=cur_sp;
    ((uint32_t*)cur_sp)[1]=cst_coroutine_trampoline_wrapper;
   
    return cur_sp;
}







#endif

