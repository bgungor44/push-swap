#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int value;            // Sayının kendisi
	int index;            // Sıralamadaki hedef konumu
	struct s_stack *next; // Sonraki düğüm
	struct s_stack *prev; // Önceki düğüm
}	t_stack;

#endif