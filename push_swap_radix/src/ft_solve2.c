/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:36:43 by mehill            #+#    #+#             */
/*   Updated: 2021/10/16 23:46:04 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void ft_swap_ints(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_helper(t_param *param, t_move *mv, int elm2)
{
while (param->b->size < 2)
	{
		if (ft_getindex(*(param->a), 0) == 4 || ft_getindex(*(param->a), 0) == 5)
		{
			ft_catchar(param->str, param->mvs->pb(param->a, param->b));
			if (ft_step_top(param->a, elm2) > 0)
				mv = param->mvs->ra;
			else
				mv = param->mvs->rra;
		}
		if (ft_getindex(*(param->a), 0) == 4 || ft_getindex(*(param->a), 0) == 5)
			ft_catchar(param->str, param->mvs->pb(param->a, param->b));
		if (param->b->size == 2)
			break ;
		ft_catchar(param->str, mv(param->a, param->b));
	}
}

void	ft_solve_m(t_param * param)
{
	int 	elm1;
	int		elm2;
	t_move	*mv;

	elm1 = 4;
	elm2 = 5;
	if (ft_abs(ft_step_top(param->a, 4)) > ft_abs(ft_step_top(param->a, 5)))
		ft_swap_ints(&elm1, &elm2);
	if (ft_step_top(param->a, elm1) > 0)
		mv = param->mvs->ra;
	else
		mv = param->mvs->rra;
	ft_helper(param, mv, elm2);
	if (ft_issorted(param->b, ACC) == 0)
			ft_catchar(param->str, param->mvs->sb(param->a, param->b));
	ft_solve_s(param);
	ft_catchar(param->str, param->mvs->pa(param->a, param->b));
	ft_catchar(param->str, param->mvs->ra(param->a, param->b));
	ft_catchar(param->str, param->mvs->pa(param->a, param->b));
	ft_catchar(param->str, param->mvs->ra(param->a, param->b));
}
