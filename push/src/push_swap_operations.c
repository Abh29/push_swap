#include "push_swap.h"

int	find_max_in_stack(t_list *ptr)
{
	int	max;

	max = ptr->index;
	while (ptr)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}
	return (max);
}

void	find_max_in_stack_A(t_stack *s)
{
	t_list	*ptr;

	ptr = (*s->stack_a);
	s->max = ptr->index;
	while (ptr)
	{
		if (ptr->index > s->max)
			s->max = ptr->index;
		ptr = ptr->next;
	}
}

int	find_min_in_stack(t_list *ptr)
{
	int	min;

	min = ptr->index;
	while (ptr)
	{
		if (ptr->index < min)
			min = ptr->index;
		ptr = ptr->next;
	}
	return (min);
}

void	move_element_to_first(t_stack *s)

{
	if (s->place > ft_lstsize(*s->stack_a) / 2)
	{
		while ((*s->stack_a)->index != s->working_index)
			rra(s);
		pb(s);
	}
	else
	{
		while ((*s->stack_a)->index != s->working_index)
			ra(s);
		pb(s);
	}
}

void	place_zero_as_first_elem(t_stack *s)

{
	int	place;

	place = 0;
	s->ptr = (*s->stack_a);
	while (s->ptr)
	{
		if (s->ptr->index == 0)
			s->place = place;
		place++;
		s->ptr = s->ptr->next;
	}
	if (s->place < ft_lstsize(*s->stack_a) / 2)
	{
		while ((*s->stack_a)->index != 0)
			ra(s);
	}
	else
	{
		while ((*s->stack_a)->index != 0)
			rra(s);
	}
}	
