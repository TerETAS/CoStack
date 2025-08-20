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



uint32_t cst_stask_init(costack_t *task,uint32_t (*fun)(void* ),void* stack_base,uint32_t stack_size);
uint32_t cst_yield(costack_t *task);
uint32_t cst_task_call(costack_t *task);


#include "csr_event.h"
#include "csr_event_group.h"
#include "csr_semaphore.h"





#endif