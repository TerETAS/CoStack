//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//
#ifndef __CSR_EVENT_H__
#define __CSR_EVENT_H__

#include "costack.h"


typedef struct csr_event_t{

    uint32_t event;
    //todo hook 
    int      (*hook)();

}csr_event_t;



int csr_event_init(csr_event_t * event);
int csr_event_acquired(csr_event_t * event);
int csr_event_release(csr_event_t * event);








#endif