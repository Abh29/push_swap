#include "../push_swap.h"

char	*ft_ra(t_stack *a, t_stack *b)
{
	int elm;

	if (!a || !b)
		return (NULL);
	(void) b;
	elm = ft_pop(a);
	ft_pushbottom(a, elm);
	return ("ra");
}

char	*ft_rb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	ft_ra(b, a);
	return ("rb");
}

char 	*ft_rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	ft_ra(a, b);
	ft_rb(a, b);
	return ("rr");
}

char	*ft_pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	if (ft_isempty(b) || ft_isfull(a))
		return (NULL);
	ft_push(a, ft_pop(b));
	return ("pa");
}

char	*ft_pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (NULL);
	if (ft_isempty(a) || ft_isfull(b))
		return (NULL);
	ft_push(b, ft_pop(a));
	return ("pb");
}