//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __CSR_EVENT_GROUP_H__
#define __CSR_EVENT_GROUP_H__

#include "costack.h"


typedef struct csr_event_group_t{

    uint32_t flag_group;
    //todo hook 
    int      (*hook)();

}csr_event_group_t;



int csr_event_group_init(csr_event_group_t * event);
int csr_event_group_acquired(csr_event_group_t * event,uint32_t flag_select);
int csr_event_group_release(csr_event_group_t * event,uint32_t flag_select);








#endif
