#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) // Sonrakinin boş olduğu yere kadar git
		stack = stack->next;
	return (stack);
}
