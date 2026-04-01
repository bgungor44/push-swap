#include "push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!*stack) // Liste boşsa
	{
		*stack = new_node;
		new_node->next = NULL; // Sonraki yok
		new_node->prev = NULL; // Önceki de yok
		return ;
	}
	new_node->next = *stack;   // Yeni düğümün önü eski başa bağlanır
	(*stack)->prev = new_node; // Eski başın arkası yeniye bağlanır
	*stack = new_node;         // Yığının başı artık yeni düğümdür
	new_node->prev = NULL;     // En başta olduğu için arkası NULL olmalı
}
