#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_moves mvs;
	t_stack a;
	t_stack b;
	t_param param;

	ft_init(&mvs);
	a = ft_newstack();
	b = ft_newstack();
	ft_read_args(argc, argv, &a);
	ft_printstack(&a);
	param.a = &a;
	param.b = &b;
	param.mvs = &mvs;
	param.str = ft_newString(1000);
	ft_printboth(&a, &b);
	printf("\n\n\n");
	getchar();
	ft_solve_big(&param);
	ft_printboth(param.a, param.b);
	printf("%s\n", param.str->str);
	return (0);
}
