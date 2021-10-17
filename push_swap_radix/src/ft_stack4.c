/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:47:45 by mehill            #+#    #+#             */
/*   Updated: 2021/10/16 22:47:50 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_stk(t_stack a)
{
	int	out;
	int	i;

	out = ft_getindex(a, 0);
	i = 1;
	while (i < a.size)
	{
		if (out < ft_getindex(a, i))
			out = ft_getindex(a, i);
		i++;
	}
	return (out);
}

int	ft_min_stk(t_stack a)
{
	int	out;
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
