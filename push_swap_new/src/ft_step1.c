/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:44:06 by mehill            #+#    #+#             */
/*   Updated: 2021/10/17 00:00:28 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_swap(t_stack *a, t_moves *mvs, int *last_head)
{
	 int		osize;
	 int		tmp[MAX_SIZE];
	 t_stack	dup;
	 int		nsize;
	 int		head;

	ft_stkdup(*a, &dup);
	ft_stk_arr_head(*a, tmp, ft_find_head(*a));
	osize = ft_lis_length(tmp, a->size);
	mvs->sa(&dup, NULL);
	head = ft_find_head(dup);
	ft_stk_arr_head(dup, tmp, head);
	nsize = ft_lis_length(tmp, dup.size);
	if (nsize > osize)
	{
		*last_head = head;
		return (1);
	}
	return (0);
}

void	ft_push_to_b(t_param *param)
{
	int	head;
	int	i;
	int	lis[MAX_SIZE];
	int	keys[MAX_SIZE];
	int	length;

	head = ft_find_head(*(param->a));
	if (ft_check_swap(param->a, param->mvs, &head))
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
	i = 0;
	ft_stk_arr_head(*(param->a), keys, head);
	length = ft_lis_length(keys, param->a->size);
	if (length == param->a->size)
		return ;
	ft_find_lis(keys, lis, param->a->size);
	while (i < param->a->size)
	{
		if (ft_indexOf(lis, length, \
		ft_getindex(*(param->a), 0)) == -1 && i--)
			ft_catchar(param->str, param->mvs->pb(param->a, param->b));
		else
			ft_catchar(param->str, param->mvs->ra(param->a, param->b));
		i++;
	}
}
