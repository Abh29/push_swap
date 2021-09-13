#include "../push_swap.h"

char	ft_rra(t_stack *a, t_stack *b)
{
	int elm;

	if (!a || !b)
		return (0);
	(void) b;
	elm = ft_popbottom(a);
	ft_push(a, elm);
	return ('i');
}

char	ft_rrb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_rra(b, a);
	return ('j');
}

char	ft_rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_rra(a, b);
	ft_rrb(a, b);
	return ('k');
}