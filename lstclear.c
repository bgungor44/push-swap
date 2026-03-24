#include "push_swap.h"

void stack_clear(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        tmp = (*stack)->next; // Bir sonrakini güvenli yere al
        free(*stack);         // Mevcut olanı temizle 
        *stack = tmp;         // Bir sonrakine geç
    }
    *stack = NULL; // İşi garantiye alalım
}