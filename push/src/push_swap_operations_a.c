#include "push_swap.h"

void	pa(t_stack *s)
{
	t_list	*stack_b_elem1;
	t_list	*stack_b_elem0;
	t_list	*stack_a_elem0;

	if (!(*s->stack_b))
		return ;
	stack_b_elem0 = *s->stack_b;
	stack_b_elem1 = (*s->stack_b)->next;
	*s->stack_b = stack_b_elem1;
	stack_a_elem0 = *(s->stack_a);
	*s->stack_a = stack_b_elem0;
	stack_b_elem0->next = stack_a_elem0;
	ft_putstr_fd("pa\n", 1);
}

void	sa(t_stack *s)
{
	t_list	*elem2;
	t_list	*elem1;

	if (!(*s->stack_a) || !((*s->stack_a)->next))
		return ;
	elem2 = (*s->stack_a)->next->next;
	elem1 = (*s->stack_a)->next;
	elem1->next = *s->stack_a;
	elem1->next->next = elem2;
	*s->stack_a = elem1;
	ft_putstr_fd("sa\n", 1);
}

void	ra(t_stack *s)
{
	t_list	*last;
	t_list	*elem1;

	if (!(*s->stack_a) || !((*s->stack_a)->next))
		return ;
	elem1 = (*s->stack_a)->next;
	last = ft_lstlast(*s->stack_a);
	last->next = *s->stack_a;
	(*s->stack_a)->next = 0;
	*s->stack_a = elem1;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *s)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*s->stack_a) || !((*s->stack_a)->next))
		return ;
	before_last = ft_lst_before_last(*s->stack_a);
	last = before_last->next;
	before_last->next = 0;
	last->next = *s->stack_a;
	*s->stack_a = last;
	ft_putstr_fd("rra\n", 1);
}
