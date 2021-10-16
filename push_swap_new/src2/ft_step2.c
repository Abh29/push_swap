/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:44:29 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 19:51:11 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_to_a(t_param *param)
{
	int	best;

	best = ft_get_best(param);
	printf("this is the best to move back idx: %d  elm: %d\n", best, ft_getindex(*(param->b), best));
	printf("moves %d\n", ft_get_moves(param, ft_getindex(*(param->b), best)));
	printf("these are the curent a and b \n");
	ft_printboth(param->a, param->b);
}
