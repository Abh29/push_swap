#include "../push_swap.h"
#include <stdio.h>


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

void	ft_printarr(int *arr, int size, int fd)
{
	int i;

	if (arr == NULL)
	{
		ft_putstr_fd("(null)\n", fd);
		return ;
	}
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i++], fd);
		ft_putstr_fd(" , ", fd);
	}
	ft_putstr_fd("\n", fd);
}

void	ft_printHnode(t_Hnode *hnode)
{
	ft_printboth(&(hnode->a), &(hnode->b));
	ft_putstr_fd("\n", 1);
}
