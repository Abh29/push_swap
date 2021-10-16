#include "push_swap.h"
#include <stdio.h>

void	ft_invert_stk(t_stack *stk)
{
	int i;

	i = 0;
	while (i < stk->size)
		stk->arr[i++] *= -1;
}

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
	//getchar();
	ft_solve_big(&param);
	ft_printboth(param.a, param.b);
	printf("%s\n", param.str->str);
	return (0);
}


int main_(int argc, char **argv)
{
	t_moves mvs;
	t_stack a;
	t_stack b;
	t_param param;
	(void) argv;
	(void) argc;
	ft_init(&mvs);
	a = ft_newstack();
	b = ft_newstack();
	ft_push(&a, 6);
	ft_push(&a, 5);
	ft_push(&a, 4);
	ft_push(&a, 1);
	ft_push(&b, 3);
	ft_push(&b, 2);
	param.a = &a;
	param.b = &b;
	param.mvs = &mvs;
	(void) param;
	printf("a = %d\n", ft_step_proper(&a, 2));
	printf("b = %d\n",ft_step_top(&b, 2));

	return (0);
}
