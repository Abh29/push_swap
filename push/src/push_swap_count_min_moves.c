#include "push_swap.h"

void	count_RB_RRB(t_stack *s)
{
	int	place;
	int	size_b;

	size_b = ft_lstsize(*s->stack_b);
	place = 0;
	s->ptr = (*s->stack_b);
	if (size_b > 1)
	{
		while (s->ptr)
		{
			s->ptr->rb_to_B0 = place;
			s->ptr->rrb_to_B0 = size_b - place;
			s->ptr = s->ptr->next;
			place++;
		}
	}
	else
	{
		s->ptr->rrb_to_B0 = 0;
		s->ptr->rb_to_B0 = 0;
	}
}

void	count_RA_RRA(t_stack *s)
{
	int	size_a;

	size_a = ft_lstsize(*s->stack_a);
	s->ptr = (*s->stack_b);
	if (size_a > 1)
	{
		while (s->ptr)
		{
			s->ptr->ra_to_A0 = s->ptr->place_in_A;
			s->ptr->rra_to_A0 = size_a - s->ptr->place_in_A;
			s->ptr = s->ptr->next;
		}
	}
}

static void	count_rrx(t_stack *s)
{
	if (s->ptr->rra_to_A0 > s->ptr->rrb_to_B0)
	{
		s->ptr->rrr_to_A0_B0 = s->ptr->rrb_to_B0;
		s->ptr->rra_to_A0 -= s->ptr->rrr_to_A0_B0;
		s->ptr->rrb_to_B0 = 0;
	}
	else if (s->ptr->rra_to_A0 < s->ptr->rrb_to_B0)
	{
		s->ptr->rrr_to_A0_B0 = s->ptr->rra_to_A0;
		s->ptr->rrb_to_B0 -= s->ptr->rrr_to_A0_B0;
		s->ptr->rra_to_A0 = 0;
	}
	else
	{
		s->ptr->rrr_to_A0_B0 = s->ptr->rra_to_A0;
		s->ptr->rra_to_A0 = 0;
		s->ptr->rrb_to_B0 = 0;
	}
}

static void	count_rx(t_stack *s)
{
	if (s->ptr->ra_to_A0 > s->ptr->rb_to_B0)
	{
		s->ptr->rr_to_A0_B0 = s->ptr->rb_to_B0;
		s->ptr->ra_to_A0 -= s->ptr->rr_to_A0_B0;
		s->ptr->rb_to_B0 = 0;
	}
	else if (s->ptr->ra_to_A0 < s->ptr->rb_to_B0)
	{
		s->ptr->rr_to_A0_B0 = s->ptr->ra_to_A0;
		s->ptr->rb_to_B0 -= s->ptr->rr_to_A0_B0;
		s->ptr->ra_to_A0 = 0;
	}
	else
	{
		s->ptr->rr_to_A0_B0 = s->ptr->ra_to_A0;
		s->ptr->ra_to_A0 = 0;
		s->ptr->rb_to_B0 = 0;
	}
}

void	count_RR_RRR(t_stack *s)
{
	s->ptr = (*s->stack_b);
	if (ft_lstsize(*s->stack_b) > 1)
	{
		while (s->ptr)
		{
			count_rx(s);
			count_rrx(s);
			s->ptr = s->ptr->next;
		}
	}
	else
	{
		s->ptr->rrb_to_B0 = 0;
		s->ptr->rb_to_B0 = 0;
		s->ptr->rr_to_A0_B0 = 0;
		s->ptr->rrr_to_A0_B0 = 0;
	}
}
