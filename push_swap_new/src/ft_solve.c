/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:35:09 by mehill            #+#    #+#             */
/*   Updated: 2021/10/17 00:15:11 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_fill_info(t_solve *info, t_stack *a, t_stack *b)
{
	int	arr[MAX_SIZE];
	int	ord[MAX_SIZE];

	info->a = a;
	info->b = b;
	info->sizeA = 0;
	ft_stk_to_arr(*a, arr);
	ft_sorted_arr(*a, ord);
	while (info->sizeA < a->size)
	{
		info->idxA[info->sizeA] = ft_indexOf(arr, a->size, ord[info->sizeA]);
		info->sizeA++;
	}
	info->sizeB = 0;
	ft_stk_to_arr(*b, arr);
	ft_sorted_arr(*b, ord);
	while (info->sizeB < b->size)
	{
		info->idxB[info->sizeB] = ft_indexOf(arr, b->size, ord[info->sizeB]);
		info->sizeB++;
	}	
}

void	ft_solve_s(t_param *param)
{
	int			desc;
	t_solve		info;

	ft_fill_info(&info, param->a, param->b);
	desc = info.idxA[0] * 100 + info.idxA[1] * 10 + info.idxA[2];
	if (desc == 12)
		return ;
	if (desc == 21)
	{
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
		ft_catchar(param->str, param->mvs->ra(param->a, param->b));
	}
	else if (desc == 102)
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
	else if (desc == 120)
		ft_catchar(param->str, param->mvs->ra(param->a, param->b));
	else if (desc == 201)
		ft_catchar(param->str, param->mvs->rra(param->a, param->b));
	else if (desc == 210)
	{
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
		ft_catchar(param->str, param->mvs->rra(param->a, param->b));
	}
}

void	ft_solve_m(t_param *param)
{
	int	max;
	int	min;
	int	keys[MAX_SIZE];

	max = ft_max_stk(*(param->a));
	min = ft_min_stk(*(param->a));
	ft_stk_arr_head(*(param->a), keys, min);
	if (ft_lis_length(keys, param->a->size) == param->a->size)
	{
		max = ft_step_top(param->a, min);
		if (max > 0)
			ft_move_rep(param->mvs->ra, param, max);
		else if (max < 0)
			ft_move_rep(param->mvs->rra, param, max * -1);
		return ;
	}
	min = ft_step_top(param->a, max);
	if (min > 0)
		ft_move_rep(param->mvs->ra, param, min);
	else if (min < 0)
		ft_move_rep(param->mvs->rra, param, min * -1);
	ft_catchar(param->str, param->mvs->pb(param->a, param->b));
	ft_solve_s(param);
	ft_catchar(param->str, param->mvs->pa(param->a, param->b));
	ft_catchar(param->str, param->mvs->ra(param->a, param->b));
}

void	ft_solve_l(t_param *param)
{
	ft_push_to_b(param);
	ft_push_to_a(param);
}

void	ft_solve(t_param *param)
{
	if (param->a->size == 3)
		ft_solve_s(param);
	else if (param->a->size == 4)
		ft_solve_m(param);
	else
		ft_solve_l(param);
}
