/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:44:29 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 19:11:46 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_move_rep(t_move *mv, t_param *param, int rep)
{
	if (rep < 1)
		return ;
	while (rep-- > 0)
		ft_catchar(param->str, mv(param->a, param->b));
}

void	ft_move_to_pos(t_param *param, int elm)
{
	int	a;
	int	b;

	b = ft_step_top(param->b, elm);
	a = ft_step_proper(param->a, elm);
	printf("this is a: %d, b: %d\n", a, b);
	if (a * b > 0)
	{
		if (a < 0)
		{
			if (b < a)
			{
				ft_move_rep(param->mvs->rr, param, a * -1);
				ft_move_rep(param->mvs->rb, param, (b - a) * -1);
			}
			else
			{
				ft_move_rep(param->mvs->rr, param, b * -1);
				ft_move_rep(param->mvs->ra, param, (a - b) * -1);
			}
		}
		else
		{
			if (a < b)
			{
				ft_move_rep(param->mvs->rrr, param, a);
				ft_move_rep(param->mvs->rrb, param, b - a);
			}
			else
			{
				ft_move_rep(param->mvs->rrr, param, b);
				ft_move_rep(param->mvs->rra, param, a - b);
			}
		}
	}
	else
	{
		if (a > 0)
			ft_move_rep(param->mvs->ra, param, a);
		else
			ft_move_rep(param->mvs->rra, param, a * -1);
		if (b > 0)
			ft_move_rep(param->mvs->rb, param, b);
		else
			ft_move_rep(param->mvs->rrb, param, b * -1);
	}
	printf("*****before moving back to A****\n");
	ft_printboth(param->a, param->b);

	printf("****************\n\n");
	ft_move_rep(param->mvs->pa, param, 1);
}

void	ft_push_to_a(t_param *param)
{
	int	best;
	int	elm;
	int	i;

	printf("\n\n--------------\n");
	ft_printboth(param->a, param->b);
	printf("\n------------\n\n");

	while (ft_isempty(param->b) == 0)
	{
		ft_printboth(param->a, param->b);
		best = ft_get_best(param);
		elm = ft_getindex(*(param->b), best);
		printf("this is the best to move back idx: %d  elm: %d\n", best, elm);
		printf("moves %d\n", ft_get_moves(param, elm));
		printf("these are the curent a and b \n");
		printf("%s\n", param->str->str);
		ft_move_to_pos(param, elm);
		ft_printboth(param->a, param->b);
	}
	printf("this is the last \n");
	ft_printboth(param->a, param->b);
	elm = ft_min_stk(*(param->a));
	if (elm == ft_getindex(*(param->a), 0))
		return ;
	i = ft_step_proper(param->a, elm);
	if (i > 0)
		ft_move_rep(param->mvs->ra, param, i + 1);
	else if (i < 0)
		ft_move_rep(param->mvs->rra, param, i * -1 + 1);
}
