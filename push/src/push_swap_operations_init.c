#include "push_swap.h"

void	elem_init(t_list *elem)
{
	elem->to_stack_B = 0;
	elem->next = NULL;
	elem->index = -1;
	elem->index_flag = 0;
	elem->seq_count = 0;
	elem->num_in_A = 0;
	elem->place_in_A = 0;
	elem->rrb_to_B0 = 0;
	elem->rb_to_B0 = 0;
	elem->rrr_to_A0_B0 = 0;
	elem->ra_to_A0 = 0;
	elem->rra_to_A0 = 0;
	elem->rr_to_A0_B0 = 0;
}

void	stack_init(t_stack *s)
{
	s->seq = NULL;
	s->working_index = 0;
	s->ptr = NULL;
	s->place = 0;
	s->initial_stack_size = 0;
	s->max = 0;
	s->magic_num = 0;
	s->stack_a = (t_list **) malloc(sizeof(t_list *));
	s->stack_b = (t_list **) malloc(sizeof(t_list *));
	*s->stack_a = NULL;
	*s->stack_b = NULL;
	s->magic_num_ptr = NULL;
}
