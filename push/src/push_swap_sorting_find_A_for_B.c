#include "push_swap.h"

static int	int_loop_num(t_stack *s, t_list *ptr_A, int a_num, int b_num)
{
	while (ptr_A)
	{
		if (b_num > ptr_A->index)
		{
			ptr_A = ptr_A->next;
			if (b_num < ptr_A->index)
				a_num = ptr_A->index;
		}
		if (b_num < ptr_A->index)
		{
			if (b_num > (ft_lstlast(*s->stack_a)->index))
			{
				a_num = ptr_A->index;
				break ;
			}
			else
				ptr_A = ptr_A->next;
		}
	}
	return (a_num);
}

static void	int_loop_place(t_stack *s, t_list *ptr_A, int a_num)
{
	int	place;

	place = 0;
	ptr_A = (*s->stack_a);
	while (ptr_A && ptr_A->index != a_num)
	{
		place++;
		ptr_A = ptr_A->next;
	}
	s->ptr->num_in_A = a_num;
	s->ptr->place_in_A = place;
}

void	int_loop(t_stack *s)
{
	t_list	*ptr_A;
	int		b_num;
	int		a_num;
	int		min;
	int		max;

	max = find_max_in_stack((*s->stack_a));
	min = find_min_in_stack((*s->stack_a));
	a_num = 0;
	b_num = s->ptr->index;
	ptr_A = NULL;
	if ((*s->stack_a))
		ptr_A = (*s->stack_a);
	else
		s->ptr->place_in_A = 0;
	if (b_num > max)
		a_num = min;
	else if (b_num < min)
		a_num = min;
	else
		a_num = int_loop_num(s, ptr_A, a_num, b_num);
	int_loop_place(s, ptr_A, a_num);
}

void	find_num_A_for_each_B(t_stack *s)
{
	s->ptr = (*s->stack_b);
	while (s->ptr)
	{
		int_loop(s);
		s->ptr = s->ptr->next;
	}
}
