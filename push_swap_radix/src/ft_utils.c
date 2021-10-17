#include "../push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	ft_step_top(t_stack *a, int elm)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (ft_getindex(*a, i) == elm)
			break ;
		i++;
	}
	if (i > a->size / 2)
		i -= a->size;
	return (i);
}
