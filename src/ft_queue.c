#include "../push_swap.h"

t_Hnode2	*ft_newHnode2(t_stack a, t_stack b, int step)
{
	t_Hnode2	*out;

	out = malloc(sizeof(t_Hnode));
	if (out == NULL)
		ft_exit("Error : memory allocation error !\n", 2);
	out->hash = ft_hashcode_node(a, b);
	out->str = ft_newString(500);
	out->step = step;
	return (out);
}

t_Hnode	*ft_newHnode(t_stack a, t_stack b, int step)
{
	t_Hnode	*out;

	out = malloc(sizeof(t_Hnode));
	if (out == NULL)
		ft_exit("Error : memory allocation error !\n", 2);
	ft_stkdup(a, &(out->a));
	ft_stkdup(b, &(out->b));
	out->hash = ft_hashcode_node(a, b);
	out->str = ft_newString(500);
	out->step = step;
	return (out);
}



void	ft_Qpush(t_list **q, t_list *elm)
{
	ft_lstadd_front(q, elm);
}

t_list	*ft_Qpop(t_list **q)
{
	t_list	*last;

	last = ft_lstlast(*q);
	if (*q == last)
		*q = NULL;
	else
	{
		while ((*q)->next != last)
			*q = (*q)->next;
		(*q)->next = NULL;
	}
	return (last);
}

int		ft_eqlHnode(t_Hnode *a, t_Hnode *b)
{
	if (a == b)
		return (1);
	if (a->hash != b->hash)
		return (0);
	if (ft_equstack(a->a, b->a) == 0)
		return (0);
	if (ft_equstack(a->b, b->b) == 0)
		return (0);
	return (1);
}

int		ft_eqlHNode(t_stack *origina, t_stack *originb, t_Hnode *a, t_Hnode *b)
{
	t_stack		tmp[4];
	t_moves		mvs;


	if (a == b)
		return (1);
	if (a->hash != b->hash)
		return (0);
	ft_init(&mvs);
	ft_stkdup(*origina, &tmp[0]);
	ft_stkdup(*origina, &tmp[2]);
	ft_stkdup(*originb, &tmp[1]);
	ft_stkdup(*originb, &tmp[3]);
	ft_getstacks(*a, &tmp[0], &tmp[1], mvs);
	ft_getstacks(*b, &tmp[2], &tmp[3], mvs);
	if (ft_equstack(tmp[0], tmp[2]) == 0)
		return (0);
	if (ft_equstack(tmp[1], tmp[3]) == 0)
		return (0);
	return (1);
}

void	ft_getstacks(t_Hnode node, t_stack *origina, t_stack *originb, t_moves mvs)
{
	char	*tmp;

	tmp = node.str->str;
	while (*tmp)
	{
		ft_moveChar(*tmp, origina, originb, mvs);
		tmp++;
	}
}

void	ft_moveChar(char c, t_stack *a, t_stack *b, t_moves mvs)
{
	if (c == 'a')
		mvs.sa(a, b);
	else if (c == 'b')
		mvs.sb(a, b);
	else if (c == 'c')
		mvs.ss(a, b);
	else if (c == 'd')
		mvs.ra(a, b);
	else if (c == 'e')
		mvs.rb(a, b);
	else if (c == 'f')
		mvs.rr(a, b);
	else if (c == 'g')
		mvs.pa(a, b);
	else if (c == 'h')
		mvs.pb(a, b);
	else if (c == 'i')
		mvs.rra(a, b);
	else if (c == 'j')
		mvs.rrb(a, b);
	else if (c == 'k')
		mvs.rrr(a, b);	
}

