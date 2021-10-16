#include "push_swap.h"

void	pb(t_stack *s)
{
	t_list	*stack_a_elem1;
	t_list	*stack_a_elem0;
	t_list	*stack_b_elem0;

	if (!(*s->stack_a))
		return ;
	stack_a_elem0 = *s->stack_a;
	stack_a_elem1 = (*s->stack_a)->next;
	*s->stack_a = stack_a_elem1;
	stack_b_elem0 = *(s->stack_b);
	*s->stack_b = stack_a_elem0;
	stack_a_elem0->next = stack_b_elem0;
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *s)
{
	t_list	*last;
	t_list	*elem1;

	if (!(*s->stack_b) || !((*s->stack_b)->next))
		return ;
	elem1 = (*s->stack_b)->next;
	last = ft_lstlast(*s->stack_b);
	last->next = *s->stack_b;
	(*s->stack_b)->next = 0;
	*s->stack_b = elem1;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *s)
{
	t_list	*last;
	t_list	*elem1;

	ft_putstr_fd("rr\n", 1);
	if (!(*s->stack_a) || !((*s->stack_a)->next))
		return ;
	elem1 = (*s->stack_a)->next;
	last = ft_lstlast(*s->stack_a);
	last->next = *s->stack_a;
	(*s->stack_a)->next = 0;
	*s->stack_a = elem1;
	if (!(*s->stack_b) || !((*s->stack_b)->next))
		return ;
	elem1 = (*s->stack_b)->next;
	last = ft_lstlast(*s->stack_b);
	last->next = *s->stack_b;
	(*s->stack_b)->next = 0;
	*s->stack_b = elem1;
}

void	rrb(t_stack *s)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*s->stack_b) || !((*s->stack_b)->next))
		return ;
	before_last = ft_lst_before_last(*s->stack_b);
	last = before_last->next;
	before_last->next = 0;
	last->next = *s->stack_b;
	*s->stack_b = last;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *s)
{
	t_list	*last;
	t_list	*before_last;

	ft_putstr_fd("rrr\n", 1);
	if (!(*s->stack_a) || !((*s->stack_a)->next))
		return ;
	before_last = ft_lst_before_last(*s->stack_a);
	last = before_last->next;
	before_last->next = 0;
	last->next = *s->stack_a;
	*s->stack_a = last;
	if (!(*s->stack_b) || !((*s->stack_b)->next))
		return ;
	before_last = ft_lst_before_last(*s->stack_b);
	last = before_last->next;
	before_last->next = 0;
	last->next = *s->stack_b;
	*s->stack_b = last;
}
