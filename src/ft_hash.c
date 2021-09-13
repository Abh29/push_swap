#include "../push_swap.h"

long	ft_hashcode(int *arr, int length)
{
	long	hash;
	int		i;

	if (arr == NULL)
		return (-1);
	hash = 17;
	i = 0;
	while (i < length)
		hash = hash * 19 + arr[i++];
	return (hash);
}

long	ft_hashcode_node(t_stack a, t_stack b)
{
	long 	hash;

	hash = 17;
	while (1)
	{
		if (!ft_isempty(&a))
			hash = hash * 19 + ft_pop(&a);
		if (!ft_isempty(&b))
			hash = hash * 19 + ft_pop(&b);
		if (ft_isempty(&a) && ft_isempty(&b))
			break ;
	}
	return hash;
}
