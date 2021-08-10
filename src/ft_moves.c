#include "../push_swap.h"

char	*ft_sa(t_stack *a, t_stack *b)
{
	int c;
	int idx1;
	int idx2;

	if (!a  || !b || a->size < 2)
		return (NULL);
	(void) b;
	idx1 = (a->tail + MAX_SIZE - 1) % MAX_SIZE;
	idx2 = (idx1 + MAX_SIZE - 1) % MAX_SIZE;
	c = a->arr[idx1];
	a->arr[idx1] = a->arr[idx2];
	a->arr[idx2] = c;
	return ("ra");
}

char	*ft_sb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	ft_sa(b, a);
	return ("sb");
}

char 	*ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	ft_sa(a, b);
	ft_sb(a, b);
	return ("ss");
}
