//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//


#ifndef __COSTACK_H__
#define __COSTACK_H__

#include "stdint.h"


typedef  void * csr_sp_t;

typedef  struct costack_t
{
    csr_sp_t caller_sp;
    csr_sp_t callee_sp;
    void* sp_base;
    int   (*fun)(void* par);
    int   rt;

}costack_t;













#endif