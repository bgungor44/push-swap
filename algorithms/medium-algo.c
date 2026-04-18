#include "push_swap.h"

t_stack	*find_unindexed_min(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index == -1)
		{
			if (min == NULL )
				min = stack;
            else if (stack->value < min->value)
                min = stack;                                                                                           
		}
		stack = stack->next;
	}
	return (min);
}

void	indexing(t_stack *stack)
{
	t_stack	*min;
	int		i;

	i = 0;
	min = find_unindexed_min(stack);
	while (min)
	{
		min->index = i;
		i++;
		min = find_unindexed_min(stack);
	}
}


int	chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

void	push_chunks_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	limit;
	int	pushed;

	size = stack_size(*a);
	chunk_size = get_chunk_size(size);
	limit = chunk_size - 1;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= limit)
		{
			pb(a, b);
			pushed++;
			if (pushed == chunk_size)
			{
				limit += chunk_size;
				pushed = 0;
			}
		}
		else
			ra(a);
	}
}