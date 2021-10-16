/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:36:43 by mehill            #+#    #+#             */
/*   Updated: 2021/10/16 19:44:09 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_step_top(t_stack *a, int elm)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (ft_getindex(*a, i) == elm)
			break ;
		i++;
	}
	if (i > a->size / 2)
		i -= a->size;
	return (i);
}

int	ft_min_stk(t_stack a)
{
	int out;
	int	i;

	out = ft_getindex(a, 0);
	i = 1;
	while (i < a.size)
	{
		if (out > ft_getindex(a, i))
			out = ft_getindex(a, i);
		i++;
	}
	return (out);
}

int	ft_step_proper(t_stack *a, int elm)
{
	int	i;
	int min;

	i = 0;
	min = ft_min_stk(*a);
	//printf("this is the element %d   %d\n", elm, min);
	if (elm < min)
		while (ft_getindex(*a, i) != min)
			i++;
	else
		while (i < a->size)
		{
		//	printf("one %d %d %d\n",ft_getindex(*a, i), elm, ft_getindex(*a, (i + 1) % a->size));
			if (ft_getindex(*a, i) <= elm && ft_getindex(*a, (i + 1) % a->size) > elm && ++i)
				break ;
			i++;
		}
	if (i > a->size / 2)
		i -= a->size;
	return (i);
}

int	ft_get_moves(t_param *param, int elm)
{
	int	a;
	int	b;
	int	out;

	b = ft_step_top(param->b, elm);
	a = ft_step_proper(param->a, elm);
	out = a + b;
	if (a * b > 0)
	{
		if (a < 0)
		{
			if (a < b)
				out -= a;
			else
				out -= b;
		}
		else
		{
			if (a < b)
				out -= a;
			else
				out -= b;
		}
	}
	return (out);
}

int	ft_get_best(t_param *param)
{
	int	i;
	int	min;
	int	out;

	i = 0;
	out = 0;
	min = INT_MAX;
	while (i < param->b->size)
	{
		if (ft_get_moves(param, ft_getindex(*(param->b), i)) < min)
		{
			min = ft_get_moves(param, ft_getindex(*(param->b), i));
			out = i;
		}
		i++;
	}
	return (out);
}
