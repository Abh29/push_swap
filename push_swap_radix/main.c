/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:08:42 by mehill            #+#    #+#             */
/*   Updated: 2021/10/17 00:19:35 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_interprt_sol2(char c)
{
	if (c == 'f')
		ft_putstr_fd("rr\n", 1);
	else if (c == 'g')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'h')
		ft_putstr_fd("pb\n", 1);
	else if (c == 'i')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'j')
		ft_putstr_fd("rrb\n", 1);
	else if (c == 'k')
		ft_putstr_fd("rrr\n", 1);
}

void	ft_interprt_sol(t_string *str)
{
	int	i;

	i = 0;
	while (i < str->length)
	{
		if (str->str[i] == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (str->str[i] == 'b')
			ft_putstr_fd("sb\n", 1);
		else if (str->str[i] == 'c')
			ft_putstr_fd("ss\n", 1);
		else if (str->str[i] == 'd')
			ft_putstr_fd("ra\n", 1);
		else if (str->str[i] == 'e')
			ft_putstr_fd("rb\n", 1);
		else
			ft_interprt_sol2(str->str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_moves	mvs;
	t_stack	a;
	t_stack	b;
	t_param	param;

	ft_init(&mvs);
	a = ft_newstack();
	b = ft_newstack();
	ft_read_args(argc, argv, &a);
	ft_replace_args(&a);
	param.a = &a;
	param.b = &b;
	param.mvs = &mvs;
	param.str = ft_newString(1000);
	ft_solve(&param);
	ft_interprt_sol(param.str);
	  printf("sorted %d   size %d   solsize : %d\n", ft_issorted(param.a, ACC), a.size, param.str->length);
	  ft_printstack(&a);
	ft_freeString(&(param.str));
	return (0);
}
