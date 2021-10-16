#include "push_swap.h"

int	ft_min_of_rotate(t_list *ptr)
{
	int	r_count;
	int	reverse_r_count;

	reverse_r_count = ptr->rra_to_A0 + ptr->rrb_to_B0 + ptr->rrr_to_A0_B0;
	r_count = ptr->ra_to_A0 + ptr->rb_to_B0 + ptr->rr_to_A0_B0;
	if (reverse_r_count < r_count)
	{
		ptr->dir = -1;
		return (reverse_r_count);
	}
	else if (reverse_r_count > r_count)
	{
		ptr->dir = 1;
		return (r_count);
	}
	else if (r_count != 0)
	{
		ptr->dir = 1;
		return (r_count);
	}
	else
	{
		ptr->dir = 0;
		return (0);
	}
}

void	count_min_movements(t_stack *s)
{
	int	min_movement_elem_number;
	int	min_movement_count;

	s->place = -1;
	s->ptr = (*s->stack_b);
	min_movement_count = ft_min_of_rotate(s->ptr);
	min_movement_elem_number = s->ptr->index;
	while (s->ptr)
	{
		if (ft_min_of_rotate(s->ptr) < min_movement_count)
		{
			min_movement_elem_number = s->ptr->index;
			min_movement_count = ft_min_of_rotate(s->ptr);
		}
		s->ptr = s->ptr->next;
	}
	s->place = min_movement_elem_number;
}

void	move_dir(t_stack *s, t_list *ptr)
{
	if (ptr->dir == 1)
	{
		while (ptr->rr_to_A0_B0--)
			rr(s);
		while (ptr->ra_to_A0--)
			ra(s);
		while (ptr->rb_to_B0--)
			rb(s);
	}
	else if (ptr->dir == -1)
	{
		while (ptr->rrr_to_A0_B0--)
			rrr(s);
		while (ptr->rra_to_A0--)
			rra(s);
		while (ptr->rrb_to_B0--)
			rrb(s);
	}
}

void	move_num_to_stackA_move(t_stack *s)
{
	s->ptr = (*s->stack_b);
	while (s->ptr)
	{
		if (s->ptr->index == s->place)
		{
			move_dir(s, s->ptr);
			if (ft_min_of_rotate(s->ptr) < 1)
				pa(s);
			return ;
		}
		s->ptr = s->ptr->next;
	}
}

void	move_num_to_stackA(t_stack *s)
{
	while ((*s->stack_b))
	{
		count_RB_RRB(s);
		find_num_A_for_each_B(s);
		count_RA_RRA(s);
		count_RR_RRR(s);
		count_min_movements(s);
		move_num_to_stackA_move(s);
	}
	place_zero_as_first_elem(s);
}
