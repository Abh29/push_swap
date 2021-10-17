#include "push_swap.h"

void	stack_a_gen(t_stack *s)
{
	char	*ptr;

	ptr = s->seq;
	while (*(ptr))
	{
		while (*(ptr) == ' ')
			ptr++;
		if (*(ptr) == '-' || ft_isdigit(*(ptr)))
		{
			if (!*s->stack_a)
				*s->stack_a = ft_lstnew(ft_atoi(ptr, s), s);
			else
				ft_lstadd_back(s->stack_a, ft_lstnew(ft_atoi(ptr, s), s));
		}
		while (*(ptr) == '-' || ft_isdigit(*(ptr)))
			ptr++;
	}
}

void	check_dublicates(t_stack *s)
{
	t_list	*st_a_int_ptr;
	int		cmp_flag;

	s->ptr = (*s->stack_a);
	while (s->ptr)
	{
		cmp_flag = -1;
		st_a_int_ptr = (*s->stack_a);
		while (st_a_int_ptr)
		{
			if (st_a_int_ptr->num == s->ptr->num)
				cmp_flag++;
			if (cmp_flag > 0)
			{
				s->error = 1;
				push_swap_close(s);
			}
			 st_a_int_ptr = st_a_int_ptr->next;
		}
		s->ptr = s->ptr->next;
	}
}

void	stack_indexing(t_stack *s)
{
	t_list	*min_ptr;
	int		i;
	int		current_min;

	s->initial_stack_size = ft_lstsize(*s->stack_a);
	i = 0;
	while (i < s->initial_stack_size)
	{
		current_min = 2147483647;
		s->ptr = (*s->stack_a);
		while (s->ptr)
		{
			if (s->ptr->num <= current_min && s->ptr->index_flag == 0)
			{
				current_min = s->ptr->num;
				min_ptr = s->ptr;
			}
			s->ptr = s->ptr->next;
		}	
		min_ptr->index_flag = 1;
		min_ptr->index = i;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		exit (0);
	stack_init(s);
	seq_validation(s, ac, av);
	stack_a_gen(s);
	check_dublicates(s);
	stack_indexing(s);
	sorting(s);
	push_swap_close(s);
	return (0);
}

//second solution 
/**
 * find the biggest consicutive deccending sequence 
 * prepare b to receive the sequence (optimize)
 * send it to b
 * repeat while a is not sorted 
 * push everything back to a
 * **/
