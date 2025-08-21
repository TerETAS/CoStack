//
// Costack
// Copyright 2025 TerETAS
// Released under an MIT license. See LICENSE file.
//

#include "./costack.h"

uint32_t cst_stask_init(costack_t *task, uint32_t (*fun)(costack_t*,void *), void *stack_base, uint32_t stack_size,void* par)
{

    task->callee_sp = cst_init_stack_fill((uint32_t)stack_base + stack_size - 1);
    task->fun = fun;
    task->sp_base = stack_base;
    task->caller_sp = 0;
    task->par = par;
    // todo: stack fill watermark
    // Initialize execution, passing its own TCB
    uint32_t rt = (uint32_t)cst_switch_to_callee(task, task);
    if (rt > (uint32_t)stack_base && rt < (uint32_t)stack_base + stack_size)
    {

        if (*(uint32_t *)rt == 0xC0FFEE)
        {
            return 0;
        }
    }
    return 1;
}

uint32_t cst_context_switch_to(cst_sp_t *src_sp_saved_ptr, cst_sp_t dst_sp, uint32_t pass_rt);

uint32_t cst_switch_to_callee(costack_t *task, uint32_t pass_rt)
{
    if (NULL == task)
    {
        // error
        while (1)
            ;
    }
    // check current process is in the caller or the callee
    if (task->caller_sp != 0 || task->callee_sp == 0)
    {
        // error
        while (1)
            ;
    }
    cst_sp_t callee_sp = task->callee_sp;
    task->callee_sp = 0;
    uint32_t rt = cst_context_switch_to(&(task->caller_sp), callee_sp, pass_rt);
}

uint32_t cst_switch_to_caller(costack_t *task, uint32_t pass_rt)
{
    if (NULL == task)
    {
        // error
        while (1)
            ;
    }

    // check current process is in the caller or the callee
    if (task->callee_sp != 0 || task->caller_sp == 0)
    {
        // error
        while (1)
            ;
    }

    cst_sp_t caller_sp = task->caller_sp;
    task->caller_sp = 0;
    uint32_t rt = cst_context_switch_to(&(task->callee_sp), caller_sp, pass_rt);
}

uint32_t cst_yield(costack_t *task)
{

    cst_switch_to_caller(task, 0);
}

uint32_t cst_task_call(costack_t *task)
{

    uint32_t rt = cst_switch_to_callee(task, NULL);

    // todo check watermark

    return rt;
}

__attribute__((noinline)) __attribute__((noreturn)) void cst_coroutine_trampoline(costack_t *task)
{
    // firt start, yield and back to caller
    uint32_t init_rt = 0xC0FFEE;
    cst_switch_to_caller(task, &init_rt);
    while (1)
    {
        uint32_t rt = task->fun(task,task->fun_par);

        // if return form task yield and back to caller
        cst_yield(task);
        // do someting or not
    }
}
