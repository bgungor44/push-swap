#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) // Sonrakinin boş olduğu yere kadar git
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack) // Liste boşsa, yeni gelen artık listenin başıdır
	{
		*stack = new_node;
		return ;
	}
	last = stack_last(*stack);
	last->next = new_node; // Eskinin önü -> Yeni
	new_node->prev = last; // Yeninin arkası -> Eski [İşte prev burada!]
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

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