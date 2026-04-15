#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);

	first = (*a)->value;
	second = (*a)->next->value;

	if (first > second)
		sa(a);
}