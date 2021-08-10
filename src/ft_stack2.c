#include "../push_swap.h"


int		ft_find(t_stack *s, int elm)
{
	int i;

	if (ft_isempty(s))
		return (-1);
	i = s->head;
	while (i != s->tail && s->arr[i] != elm)
		i = (i + 1) % MAX_SIZE;
	if (s->arr[i] == elm)
		return (i);
	return (-1);
}

int		ft_issorted(t_stack *s, int ord)
{
	int i;

	if (ord != ACC && ord != DEC)
		return (0);
	if (ft_isempty(s))
		return (1);
	i = s->head;
	if (ord == ACC)
		while (i != s->tail && s->arr[i] <= s->arr[(i + 1) % MAX_SIZE])
			i = (i + 1) % MAX_SIZE;
	else
		while (i != s->tail && s->arr[i] >= s->arr[(i + 1) % MAX_SIZE])
			i = (i + 1) % MAX_SIZE;
	if (i == s->tail)
		return (1);
	return (0);
}

void	ft_pushbottom(t_stack *s, int elm)
{
	if (ft_isfull(s))
		return ;
	s->head = (s->head + MAX_SIZE - 1) % MAX_SIZE;
	s->arr[s->head] = elm;
	s->size++;
}

int		ft_popbottom(t_stack *s)
{
	int out;

	if (ft_isempty(s))
		return (-1);
	out = s->arr[s->head];
	s->head = (s->head + 1) % MAX_SIZE;
	s->size--;
	return (out);
}
