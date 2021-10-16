#include "push_swap.h"

static void	arr_fill(int count_a_zero, int count_b_zero, t_stack *s, int *arr)
{
	int	i;
	int	j;

	i = 0;
	if (count_a_zero)
	{
		count_b_zero = s->magic_num_ptr->seq_count - count_a_zero;
		count_a_zero--;
		j = 0;
		while (count_a_zero--)
			arr[i++] = j++;
		while (count_b_zero > -1)
		{
			arr[i++] = s->magic_num_ptr->index + count_b_zero--;
		}
	}
	else
	{
		while (i < s->magic_num_ptr->seq_count)
		{
			arr[i] = s->magic_num_ptr->index + i;
			i++;
		}
	}
}

int	check_curr_num(t_stack *s, int curr_num)
{
	int	count_b_zero;
	int	*arr;
	int	i;
	int	count_a_zero;

	arr = (int *)malloc(sizeof(int) * s->magic_num_ptr->seq_count);
	count_b_zero = 0;
	count_a_zero = 0;
	if ((s->max - (s->magic_num_ptr->index + s->magic_num_ptr->seq_count)) < 0)
		count_a_zero = -(s->max - \
					(s->magic_num_ptr->index + s->magic_num_ptr->seq_count));
	arr_fill(count_a_zero, count_b_zero, s, arr);
	i = 0;
	while (i < s->magic_num_ptr->seq_count)
	{
		if (arr[i++] == curr_num)
		{
			free(arr);
			arr = NULL;
			return (1);
		}
	}
	free(arr);
	arr = NULL;
	return (0);
}

void	move_num_to_stackB(t_stack *s)
{
	int	j;

	j = 0;
	s->ptr = (*s->stack_a);
	while (j++ < s->initial_stack_size)
	{
		if (check_curr_num(s, s->ptr->index) == 0)
			s->ptr->to_stack_B = 77;
		s->ptr = s->ptr->next;
	}
	j = 0;
	while (j++ <= s->initial_stack_size)
	{
		if ((*s->stack_a)->to_stack_B == 77)
			pb(s);
		else if ((*s->stack_a)->seq_count != s->initial_stack_size)
			ra(s);
	}
	s->ptr = (*s->stack_a);
}
