//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#include "./costack.h"






uint32_t cst_stask_init(costack_t *task,uint32_t (*fun)(void* ),void* stack_base,uint32_t stack_size){

 
    //todo
    csr_stack_init((uint32_t)stack_base+stack_size-1);


}








uint32_t cst_context_switch_to(csr_sp_t * scr_sp,csr_sp_t * dst_sp,uint32_t pass_rt);


uint32_t cst_switch_callee(costack_t *task,uint32_t pass_rt){
    //check current process is in the caller or the callee
    if(task->caller_sp!=0){
        //error
        while(1);
    }
    task->caller_sp=0;
    uint32_t rt = cst_context_switch_to(&(task->caller_sp),&(task->callee_sp),pass_rt);


}


uint32_t cst_switch_caller(costack_t *task,uint32_t pass_rt){
    //check current process is in the caller or the callee
    if(task->callee_sp!=0){
        //error
        while(1){
            
        };
    }
    task->callee_sp=0;
    uint32_t rt = cst_context_switch_to(&(task->callee_sp),&(task->caller_sp),pass_rt);

}


uint32_t cst_yield(costack_t *task){

    cst_switch_caller(task,0);


}

__attribute__((noinline)) __attribute__((noreturn)) 
void cst_coroutine_trampoline(costack_t *task,void * par){

    while(1){
        uint32_t rt = task->fun(par);
        
        //if return form task yield and back to caller
        cst_yield(task);
        //do someting or not
    }
}


