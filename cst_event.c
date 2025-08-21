//
// Costack
// Copyright 2025 TerETAS
// Released under an MIT license. See LICENSE file.
//

#include "costack.h"

int cst_event_init(cst_event_t *event, int (*event_hook)(void *, cst_hook_event))
{

    if (NULL == event)
    {
        return -1;
    }
    event->event = 0;
    event->event_hook = event_hook;
    return 0;
}
int cst_event_acquired(costack_t *cur_task, cst_event_t *event)
{
    if (NULL == cur_task || NULL = event)
    {
        return -1;
    }

    while (1)
    {
        if (event->event == 1)
        {
            event->event = 0;
            return 0;
        }
        else
        {

            if (event->event_hook)
            {

                event->event_hook(event->hook_par, CST_EVENT_WAIT);
            }

            cst_yield(cur_task);
        }
    }
}
int cst_event_release(costack_t *task, cst_event_t *event)
{

    if (NULL == cur_task || NULL = event)
    {
        return -1;
    }

    event->event = 1;

    if (event->event_hook)
    {
        event->event_hook(event->hook_par, CST_EVENT_AWAKE);
    }

    return 0;
}
int cst_event_set_hook_par(cst_event_t *event, void *par)
{
    if (NULL == event)
    {
        return -1;
    }
    event->hook_par = par;
    return 0;
}
void *cst_event_get_hook_par(cst_event_t *event)
{
    if (NULL == event)
    {
        return -1;
    }

    return event->hook_par;
}
