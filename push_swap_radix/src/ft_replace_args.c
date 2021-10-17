#include "../push_swap.h"

void	ft_replace_args(t_stack *stk)
{
	int indx[MAX_SIZE];
	int	keys[MAX_SIZE];
	int i;
	int elm;
	int size;

	ft_stk_to_arr(*stk, keys);
	ft_stk_to_arr(*stk, indx);
	ft_quicksort(indx, 0, stk->size - 1);
	i = stk->size - 1;
	size = stk->size;
	stk->head = 0;
	stk->tail = 0;
	stk->size = 0;
	while (i >= 0)
	{
		elm = ft_binarySearch(indx, 0, size - 1, keys[i]) + 1;
		ft_push(stk, elm);
		i--;
	}
}
