#include "../push_swap.h"

t_stack ft_newstack()
{
	t_stack out;

	out.size = 0;
	out.head = 0;
	out.tail = 0;
	return (out);
}

void	ft_push(t_stack *s, int elm)
{
	if (!s || ft_isfull(s))
		return ;
	s->arr[s->tail] = elm;
	s->tail = (s->tail + 1) % MAX_SIZE;
	s->size++;
}

int		ft_pop(t_stack *s)
{
	int out;

	s->tail = (s->tail + MAX_SIZE - 1) % MAX_SIZE; 
	s->size--;
	out = s->arr[s->tail];
	return (out);
}

int		ft_isempty(t_stack *s)
{
	return (s->tail == s->head);
}

int		ft_isfull(t_stack *s)
{
	return ((s->tail + 1) % MAX_SIZE == s->head);
}
