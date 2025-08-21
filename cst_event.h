//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//
#ifndef __cst_EVENT_H__
#define __cst_EVENT_H__

#include "costack.h"


typedef struct cst_event_t{

    uint32_t event;

    int      (*event_hook)(void *  ,cst_hook_event );
    void * hook_par ;

}cst_event_t;



int cst_event_init(cst_event_t * event,int (*event_hook)(void *,cst_hook_event));
int cst_event_acquired(costack_t * task ,cst_event_t * event);
int cst_event_release(costack_t * task ,cst_event_t * event);
int cst_event_set_hook_par(cst_event_t * event,void* par);
void *  cst_event_get_hook_par(cst_event_t * event);







#endif