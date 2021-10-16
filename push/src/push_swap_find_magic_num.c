#include "push_swap.h"

void	scfee_internal_loop(t_stack *s, t_list *magic_number_ptr)
{
	t_list	*work_pointer;
	int		number_to_find;
	int		j;

	j = 0;
	work_pointer = magic_number_ptr;
	number_to_find = magic_number_ptr->index;
	if (magic_number_ptr->index != s->max)
		number_to_find++;
	else
		number_to_find = 0;
	while (j < s->initial_stack_size)
	{
		if (work_pointer->index == number_to_find)
		{
			number_to_find++;
			magic_number_ptr->seq_count++;
			if (number_to_find > s->max)
				number_to_find = 0;
		}
		work_pointer = work_pointer->next;
		j++;
	}
}

void	seq_count_for_every_elem(t_stack *s)
{
	t_list	*last_node_ptr;
	int		i;

	last_node_ptr = (ft_lstlast(*s->stack_a));
	last_node_ptr->next = (*s->stack_a);
	i = 0;
	s->magic_num_ptr = (*s->stack_a);
	while (i < s->initial_stack_size)
	{
		s->magic_num_ptr->seq_count = 1;
		scfee_internal_loop(s, s->magic_num_ptr);
		s->magic_num_ptr = s->magic_num_ptr->next;
		i++;
	}
	last_node_ptr->next = NULL;
}

void	find_best_magic_num(t_stack *s)
{
	int	max_seq_count;

	s->ptr = (*s->stack_a);
	max_seq_count = s->ptr->seq_count;
	while (s->ptr)
	{
		if (s->ptr->seq_count > max_seq_count)
			max_seq_count = s->ptr->seq_count;
		s->ptr = s->ptr->next;
	}
	s->ptr = (*s->stack_a);
	s->magic_num = s->max;
	while (s->ptr)
	{
		if (s->ptr->seq_count == max_seq_count)
		{
			if (s->ptr->index < s->magic_num)
			{
				s->magic_num = s->ptr->index;
				s->magic_num_ptr = s->ptr;
			}
		}
		s->ptr = s->ptr->next;
	}
	s->magic_num = s->magic_num_ptr->index;
}

void	find_num_longest_seq(t_stack *s)
{
	seq_count_for_every_elem(s);
	find_best_magic_num(s);
}
