//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __cst_SEMAPHORE_H__
#define __cst_SEMAPHORE_H__


#include "costack.h"

typedef struct cst_sem_t{

    uint32_t sem;
    int      (*event_hook)(void *  ,cst_hook_event );
    void * hook_par ;

}cst_sem_t;



int cst_sem_init(,cst_sem_t * sem,int (*event_hook)(void *,cst_hook_event));
int cst_sem_acquired(costack_t * task ,cst_sem_t * sem);
int cst_sem_release(costack_t * task ,cst_sem_t * sem);
int cst_sem_set_hook_par(cst_event_t * event,void* par);
void *  cst_sem_get_hook_par(cst_event_t * event);






#endif
