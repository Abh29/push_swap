#include "push_swap.h"
static void	clean_stack_a(t_stack *s)
{
	t_list	*ptr_before_last;

	ptr_before_last = NULL;
	if (*s->stack_a)
	{
		s->ptr = (*s->stack_a);
		while ((*s->stack_a)->next)
		{
			ptr_before_last = ft_lst_before_last(s->ptr);
			free(ptr_before_last->next);
			ptr_before_last->next = NULL;
		}
		free((*s->stack_a));
		(*s->stack_a) = NULL;
	}
	if (s->stack_a)
	{
		free(s->stack_a);
		s->stack_a = NULL;
	}
}

static void	clean_stack_b(t_stack *s)
{
	if (*s->stack_b)
	{
		s->ptr = (*s->stack_b);
		while ((*s->stack_b)->next)
		{
			free(ft_lst_before_last(s->ptr)->next);
			ft_lst_before_last(s->ptr)->next = NULL;
		}
		free((*s->stack_b));
		(*s->stack_b) = NULL;
	}
	if (s->stack_b)
	{
		free(s->stack_b);
		s->stack_b = NULL;
	}
}

void	push_swap_close(t_stack *s)
{
	if (s->error == 1)
		ft_putstr_fd("Error\n", 2);
	if (s->seq)
	{
		free(s->seq);
		s->seq = NULL;
	}
	if (s)
	{
		clean_stack_a(s);
		clean_stack_b(s);
		free(s);
		s = NULL;
	}
	exit (0);
}
