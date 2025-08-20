//
// Costack
// Copyright 2025 TerETAS 
// Released under an MIT license. See LICENSE file. 
//

#ifndef __CSR_SEMAPHORE_H__
#define __CSR_SEMAPHORE_H__


#include "costack.h"

typedef struct csr_sem_t{

    uint32_t sem;
    //todo hook 
    int      (*hook)();

}csr_sem_t;



int csr_sem_init(csr_sem_t * sem);
int csr_sem_acquired(csr_sem_t * sem);
int csr_sem_release(csr_sem_t * sem);







#endif
