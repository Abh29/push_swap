#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_moves mvs;
	t_stack a;
	t_stack b;
	t_Hnode *hnode;

	hnode = NULL;
	ft_init(&mvs);
	a = ft_newstack();
	b = ft_newstack();
	ft_read_args(argc, argv, &a);
	ft_printboth(&a, &b);
	ft_putstr_fd("running bfs \n", 1);
	hnode = ft_bfs(a, b, mvs);
	ft_printboth(&(hnode->a), &(hnode->b));
	printf("this are the steps %d \n", hnode->step);
	return (0);
}
