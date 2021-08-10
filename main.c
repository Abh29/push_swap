#include "push_swap.h"
#include <stdio.h>

void ft_init(t_moves *mvs)
{
	mvs->sa = &ft_sa;
	mvs->sb = &ft_sb;
	mvs->ss = &ft_ss;
	mvs->pa = &ft_pa;
	mvs->pb = &ft_pb;
	mvs->ra = &ft_ra;
	mvs->rb = &ft_rb;
	mvs->rr = &ft_rr;
	mvs->rra = &ft_rra;
	mvs->rrb = &ft_rrb;
	mvs->rrr = &ft_rrr;
}

char	*hello(t_stack *a, t_stack *b)
{
	(void) a;
	(void) b;
	printf("hello world !\n");
	return (NULL);
}

void	ft_printstack(t_stack *a)
{
	int i;

	if (ft_isempty(a))
	{
		ft_putstr_fd("empty stack.\n", STDOUT_FILENO);
		return ;
	}
	i = 0;
	while (i < a->size)
	{
		ft_putnbr_fd(a->arr[(a->head + i) % MAX_SIZE], STDOUT_FILENO);
		ft_putstr_fd(" , ", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_printboth(t_stack *a, t_stack *b)
{
	ft_putstr_fd("a : ", 1);
	ft_printstack(a);
	ft_putstr_fd("b : ", 1);
	ft_printstack(b);
}

int main()
{
	t_moves mvs;
	t_stack a;
	t_stack b;

	ft_init(&mvs);
	a = ft_newstack();
	b = ft_newstack();
	ft_push(&a, 10);
	ft_push(&a, 12);
	ft_push(&a, 13);
	ft_push(&b, 15);
	ft_push(&b, 14);
	ft_push(&b, 17);
	ft_printboth(&a, &b);
	mvs.rrr(&a, &b);
	ft_printboth(&a, &b);
	
	return 0;
}
