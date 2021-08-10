#include "../push_swap.h"

char	*ft_rra(t_stack *a, t_stack *b)
{
	int elm;

	if (!a || !b)
		return (NULL);
	(void) b;
	elm = ft_popbottom(a);
	ft_push(a, elm);
	return ("rra");
}

char	*ft_rrb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	ft_rra(b, a);
	return ("rrb");
}

char	*ft_rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	ft_rra(a, b);
	ft_rrb(a, b);
	return ("rrr");
}