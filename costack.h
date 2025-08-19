//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//


#ifndef __COSTACK_H__
#define __COSTACK_H__

#include "stdint.h"
#include "./arch/costack_arch_wrapper.h"

typedef  void * csr_sp_t;

typedef  struct costack_t
{
    csr_sp_t caller_sp;
    csr_sp_t callee_sp;
    void* sp_base;
    uint32_t   (*fun)(void* par);
    uint32_t   rt;
    void* par;

}costack_t;













#endif