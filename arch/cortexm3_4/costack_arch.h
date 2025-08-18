//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __COSTACK_ARCH_H__
#define __COSTACK_ARCH_H__
#include "stdint.h"


typedef struct csr_arch_save_t
{
    uint32_t  s16_s32[16];
    uint32_t  r4_r11[8];
    uint32_t  lr;    
    uint32_t  xpsr;

  
}csr_arch_save_t;



static void* csr_stack_init(void* sp_top){
    void* cur_sp;

    //todo
    return cur_sp;
}







#endif

