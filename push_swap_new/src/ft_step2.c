/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:44:29 by mehill            #+#    #+#             */
/*   Updated: 2021/10/16 23:45:16 by mehill           ###   ########.fr       */
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

static void	ft_case1(t_param *param, int a, int b)
{
	if (b < a)
	{
		ft_move_rep(param->mvs->rrr, param, a * -1);
		ft_move_rep(param->mvs->rrb, param, (b - a) * -1);
	}
	else
	{
		ft_move_rep(param->mvs->rrr, param, b * -1);
		ft_move_rep(param->mvs->rra, param, (a - b) * -1);
	}
}

static void	ft_case2(t_param *param, int a, int b)
{
	if (a < b)
	{
		ft_move_rep(param->mvs->rr, param, a);
		ft_move_rep(param->mvs->rb, param, b - a);
	}
	else
	{
		ft_move_rep(param->mvs->rr, param, b);
		ft_move_rep(param->mvs->ra, param, a - b);
	}
}

void	ft_move_to_pos(t_param *param, int elm)
{
	int	a;
	int	b;

	b = ft_step_top(param->b, elm);
	a = ft_step_proper(param->a, elm);
	if (a * b > 0)
	{
		if (a < 0)
			ft_case1(param, a, b);
		else
			ft_case2(param, a, b);
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
}

void	ft_push_to_a(t_param *param)
{
	int	best;
	int	elm;
	int	i;

	while (ft_isempty(param->b) == 0)
	{
		best = ft_get_best(param);
		elm = ft_getindex(*(param->b), best);
		ft_move_to_pos(param, elm);
		ft_move_rep(param->mvs->pa, param, 1);
	}
	elm = ft_min_stk(*(param->a));
	if (elm == ft_getindex(*(param->a), 0))
		return ;
	i = ft_step_top(param->a, elm);
	if (i > 0)
		ft_move_rep(param->mvs->ra, param, i);
	else if (i < 0)
		ft_move_rep(param->mvs->rra, param, i * -1);
}
/*
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
		printf("we have this : \n");
		ft_printboth(param->a, param->b);
		best = ft_get_best(param);
		elm = ft_getindex(*(param->b), best);
		printf("this is the best to move back idx: %d  elm: %d\n", best, elm);
		printf("moves %d\n", ft_get_moves(param, elm));
		printf("these are the curent a and b \n");
		getchar();
		printf("moving to pos...\n");
		ft_move_to_pos(param, elm);
		ft_printboth(param->a, param->b);
		getchar();
		printf("pushing ...\n");
		ft_move_rep(param->mvs->pa, param, 1);
		ft_printboth(param->a, param->b);
		printf("***************\n%s\n", param->str->str);
		getchar();
	}
	printf("finished pushing \n");
	ft_printboth(param->a, param->b);
	elm = ft_min_stk(*(param->a));
	printf("this is the head %d\n", elm);
	if (elm == ft_getindex(*(param->a), 0))
		return ;
	i = ft_step_top(param->a, elm);
	printf("this is how many steps %d\n", i);
	getchar();
	if (i > 0)
		ft_move_rep(param->mvs->ra, param, i);
	else if (i < 0)
		ft_move_rep(param->mvs->rra, param, i * -1);
}
*/