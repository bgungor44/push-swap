#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		mode;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(&a, &mode, ac, av))
	{
		write(2, "Error\n", 6);
		stack_clear(&a);
		return (1);
	}
	if (is_sorted(a) && b == NULL)
	{
		stack_clear(&a);
		return (0);
	}
	//indexing(a); /////// !!!!!!!!!!! incelenecek !!!!!!!!!
	if (mode == 1)
		simple_sort(&a, &b);
	else if (mode == 2)
		chunk_sort(&a, &b);
	// else if (mode == 3)
	// 	adaptive_sort(&a, &b);
	else if (mode == 4)
		radix_sort(&a, &b);
	else
		chunk_sort(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}