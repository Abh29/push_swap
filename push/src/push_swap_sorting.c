#include "push_swap.h"

void	sort_main(t_stack *s)
{
	find_num_longest_seq(s);
	move_num_to_stackB(s);
	move_num_to_stackA(s);
}

void	sorting(t_stack *s)
{
	find_max_in_stack_A(s);
	s->initial_stack_size = ft_lstsize(*s->stack_a);
	if (s->initial_stack_size == 1)
		push_swap_close(s);
	if (s->initial_stack_size <= 5 && s->initial_stack_size > 3)
		sort_5(s);
	else if (s->initial_stack_size <= 3)
		sort_3(s);
	else
		sort_main(s);
}
