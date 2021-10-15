#include "../push_swap.h"

char	ft_ra(t_stack *a, t_stack *b)
{
	int elm;

	if (!a || !b || a->size < 2)
		return (0);
	(void) b;
	elm = ft_pop(a);
	ft_pushbottom(a, elm);
	return ('d');
}

char	ft_rb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_ra(b, a);
	return ('e');
}

char 	ft_rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_ra(a, b);
	ft_rb(a, b);
	return ('f');
}

char	ft_pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (ft_isempty(b) || ft_isfull(a))
		return (0);
	ft_push(a, ft_pop(b));
	return ('g');
}

char	ft_pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (ft_isempty(a) || ft_isfull(b))
		return (0);
	ft_push(b, ft_pop(a));
	return ('h');
}
