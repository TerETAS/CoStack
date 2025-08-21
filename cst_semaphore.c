//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#include "costack.h"


int cst_sem_init(cst_sem_t * sem,int (*event_hook)(void *,cst_hook_event)){

    if(NULL==sem  ){
        return -1;
    }

    sem->sem=0;
    sem->event_hook=event_hook;

    return 0;
}

int cst_sem_acquired(costack_t * cur_task ,cst_sem_t * sem){
    if(NULL == cur_task || NULL == sem){
        return -1;
    }
    while(1){

        if(sem->sem){

            sem->sem-=1;

            return 0;
        }else{

            if (event->event_hook)
            {

                event->event_hook(event->hook_par, CST_EVENT_WAIT);
            }

            cst_yield(cur_task);            

        }


    }


}

int cst_sem_release(costack_t * cur_task ,cst_sem_t * sem){
    if(NULL == cur_task || NULL == sem){
        return -1;
    }
    if(sem->sem==0xFFFFFFFF){
        return -1;
    }

    sem->sem+=1;
  
    if (event->event_hook)
    {
        event->event_hook(event->hook_par, CST_EVENT_AWAKE);
    }  

    return 0;
}
int cst_sem_set_hook_par(cst_sem_t * sem,void* par){
    if(NULL == sem){
        return -1;
    }

    sem->hook_par=par;
    return 0;


}
void *  cst_sem_get_hook_par(cst_sem_t * sem){
    
    if(NULL == sem){
        return -1;
    }
    return sem->hook_par;
    
}


