#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*one;
	t_stack	*two;

	one = *a;
	two = (*a)->next;
	if (!*a || !(*a)->next)
		return ;
	one->next = two->next;
	two->next = one;
	*a = two;
}

void	ra(t_stack **a)
{
	t_stack	*one;
	t_stack	*lst;

	one = *a;
	if (!*a || !(*a)->next)
		return ;
	*a = (*a)->next;
	one->next = NULL;
	lst = stack_last(*a);
	lst->next = one;
}
void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*new_last;

	last = stack_last(*a);
	new_last = last->prev;
	new_last->next = NULL;
	last->next = *a;
    (*a)->prev = last;
	last->prev = NULL;
	*a = last;
    (*a)->prev = NULL;
}
