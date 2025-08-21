//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#include "cst_event_group.h"




int cst_event_group_init(cst_event_group_t * event,int (*event_hook)(void *,cst_hook_event),uint32_t config){

    if(event ==NULL ){
        return -1;
    }

    event->event_group=0;
    event->event_hook = event_hook;
    event->config=config;
    return 0;
}
int cst_event_group_acquired(costack_t * cur_task ,cst_event_group_t * event,uint32_t flag_select){

    if(cur_task==NULL ||event ==NULL ){
        return -1;
    }

 while(1){
    uint32_t flag = event->event_group&flag_select ;

    int result =  event->config==1? (!!flag) : (flag==flag_select);
    
    if(result){

         event->event_group&=(~flag);

        return 0;
    }else{
        if(event->event_hook){

            event->event_hook(event->hook_par,CST_EVENT_WAIT);
        }

        cst_yield(cur_task);

    }
    }

}
int cst_event_group_release(costack_t * cur_task ,cst_event_group_t * event,uint32_t flag_select){
    if(cur_task==NULL ||event ==NULL ){
        return -1;
    }
    event->event_group |= flag_select;
        if(event->event_hook){
            event->event_hook(event->hook_par,CST_EVENT_AWAKE);
        }

    return 0;

}

int cst_event_group_set_hook_par(cst_event_group_t * event,void * hook_par){
    if(event ==NULL ){
        return -1;
    }
    event->hook_par=hook_par;
    return 0;

}
void * cst_event_group_get_hook_par(cst_event_group_t * event){
    if(event ==NULL ){
        return -1;
    }
    
    return event->hook_par;
}