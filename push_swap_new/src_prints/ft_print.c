/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:34:44 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 15:35:01 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	ft_printstack(t_stack *a)
{
	int	i;

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
	int	i;

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

void	ft_printSolv(t_string *str)
{
	while (*(str->str))
	{
		if (*(str->str) == 'a')
			ft_putstr_fd("sa\n", 1);
		if (*(str->str) == 'b')
			ft_putstr_fd("sb\n", 1);
		if (*(str->str) == 'c')
			ft_putstr_fd("ss\n", 1);
		if (*(str->str) == 'd')
			ft_putstr_fd("ra\n", 1);
		if (*(str->str) == 'e')
			ft_putstr_fd("rb\n", 1);
		if (*(str->str) == 'f')
			ft_putstr_fd("rr\n", 1);
		if (*(str->str) == 'g')
			ft_putstr_fd("pa\n", 1);
		if (*(str->str) == 'h')
			ft_putstr_fd("pb\n", 1);
		if (*(str->str) == 'i')
			ft_putstr_fd("rra\n", 1);
		if (*(str->str) == 'j')
			ft_putstr_fd("rrb\n", 1);
		if (*(str->str) == 'k')
			ft_putstr_fd("rrr\n", 1);
	}
}
