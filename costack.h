//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//


#ifndef __COSTACK_H__
#define __COSTACK_H__

#include "stdint.h"
#include "./arch/costack_arch_wrapper.h"

typedef  void * cst_sp_t;

typedef  struct costack_t
{
    cst_sp_t caller_sp;
    cst_sp_t callee_sp;
    void* sp_base;
    uint32_t   (*fun)(costack_t*task , void* par);
    uint32_t   rt;
    void* fun_par;

}costack_t;


typedef enum cst_hook_event{
    CST_EVENT_WAIT,
    CST_EVENT_AWAKE
}cst_hook_event;


uint32_t cst_stask_init(costack_t *task,uint32_t (*fun)(costack_t*, void* ),void* stack_base,uint32_t stack_size,void * par);
uint32_t cst_yield(costack_t *task);
uint32_t cst_task_call(costack_t *task);


#include "cst_event.h"
#include "cst_event_group.h"
#include "cst_semaphore.h"





#endif