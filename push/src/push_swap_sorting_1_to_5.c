#include "push_swap.h"

// void	sort_3(t_stack *s)
// {
// 	if(A0 > A1 && A0 > AL) {
// 		RA;
// 		if (A0 > A1)
// 			SA;
// 	}
// 	else if(A1 > A0 && A1 > AL)
// 	{
// 		if(A0 > AL)
// 			RRA;
// 		else
// 		{
// 			SA;
// 			RA;
// 		}
// 	}
// 	else
// 	{
// 		if(A0 > A1)
// 			SA;
// 	}
// }

// void	sort_5(t_stack *s)
// {
// 	find_max_in_stack_A(s);
// 		s->place = 0;
// 		s->ptr = A0_PTR;
// 		while (s->ptr)
// 		{
// 			if (s->ptr->index == 0)
// 			{
// 				s->working_index = s->ptr->index;
// 				move_element_to_first(s);
// 			}
// 			s->place++;
// 			s->ptr = s->ptr->next;
// 		}
// 	s->place = 0;
// 	s->ptr = A0_PTR;
// 	while (s->ptr)
// 	{
// 		if (s->ptr->index == 1 && s->initial_stack_size == 5)
// 		{
// 			s->working_index = s->ptr->index;
// 			move_element_to_first(s);
// 		}
// 		s->place++;
// 		s->ptr = s->ptr->next;
// 	}
// 	sort_3(s);
// 		PA;
// 		PA;
// }

void	check_five_sort(t_stack *s)
{
	int	f;

	f = 0;
	s->ptr = (*s->stack_a);
	while (s->ptr)
	{
		if (s->ptr->next)
		{
			if (s->ptr->index > s->ptr->next->index)
				f = 1;
		}
		s->ptr = s->ptr->next;
	}
	if (f == 0)
		push_swap_close(s);
}

static void	move_zero(t_stack *s)
{
	s->place = 0;
	s->ptr = (*s->stack_a);
	while (s->ptr)
	{
		if (s->ptr->index == 0)
		{
			s->working_index = s->ptr->index;
			move_element_to_first(s);
		}
		s->place++;
		s->ptr = s->ptr->next;
	}
}

static void	move_one(t_stack *s)
{
	s->place = 0;
	s->ptr = (*s->stack_a);
	while (s->ptr)
	{
		if (s->ptr->index == 1 && s->initial_stack_size == 5)
		{
			s->working_index = s->ptr->index;
			move_element_to_first(s);
		}
		s->place++;
		s->ptr = s->ptr->next;
	}
}

void	sort_3(t_stack *s)
{
	if ((*s->stack_a)->index > (*s->stack_a)->next->index && \
		(*s->stack_a)->index > (ft_lstlast(*s->stack_a))->index)
	{
		ra(s);
		if ((*s->stack_a)->index > (*s->stack_a)->next->index)
			sa(s);
	}
	else if ((*s->stack_a)->next->index > (*s->stack_a)->index && \
			(*s->stack_a)->next->index > (ft_lstlast(*s->stack_a))->index)
	{
		if ((*s->stack_a)->index > (ft_lstlast(*s->stack_a))->index)
			rra(s);
		else
		{
			sa(s);
			ra(s);
		}
	}
	else
	{
		if ((*s->stack_a)->index > (*s->stack_a)->next->index)
			sa(s);
	}
}

void	sort_5(t_stack *s)
{
	check_five_sort(s);
	find_max_in_stack_A(s);
	move_zero(s);
	move_one(s);
	sort_3(s);
	pa(s);
	pa(s);
}
