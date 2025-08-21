//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __cst_EVENT_GROUP_H__
#define __cst_EVENT_GROUP_H__

#include "costack.h"



typedef struct cst_event_group_t{

    uint32_t event_group;
    uint32_t config;//0==and ,1 == or

    int      (*event_hook)(void *  ,cst_hook_event );
    void * hook_par ;

}cst_event_group_t;



int cst_event_group_init(cst_event_group_t * event_group,int (*event_hook)(void *,cst_hook_event),uint32_t config);
int cst_event_group_acquired(costack_t * task ,cst_event_group_t * event_group,uint32_t flag_select);
int cst_event_group_release(costack_t * task ,cst_event_group_t * event_group,uint32_t flag_select);
int cst_event_group_set_hook_par(cst_event_group_t * event_group,void * hook_par);
void * cst_event_group_get_hook_par(cst_event_group_t * event_group);






#endif
