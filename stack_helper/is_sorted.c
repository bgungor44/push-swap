#include "push_swap.h"

int is_sorted(t_stack *tmp)
{
    t_stack *a;
    a = tmp;
    if(!tmp || !tmp ->next)
        return 1;
    while(a ->next)
    {
        if(a->value > a->next->value)
            return 0;
        a = a->next;
    }
    return 1;
}
