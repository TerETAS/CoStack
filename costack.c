//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#include "./costack.h"






int cst_stask_init(costack_t *task,int (*fun)(void* ),void* stack_base,int stack_size){





}


int cst_context_switch_to(csr_sp_t * scr_sp,csr_sp_t * dst_sp);


int cst_switch_callee(costack_t *task){

    if(task->caller_sp!=0){
        return -1;
    }
    cst_context_switch_to(&(task->caller_sp),&(task->callee_sp));


}


int cst_switch_caller(costack_t *task){

    if(task->caller_sp==0){

        return -1;
    }
    cst_context_switch_to(&(task->callee_sp),&(task->caller_sp));

}


int cst_yield(costack_t *task){

    cst_switch_caller(task);


}
