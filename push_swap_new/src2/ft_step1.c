/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:44:06 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 18:15:50 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_swap(t_stack *a, t_moves *mvs, int *last_head)
{
	 int	osize;
	 int	tmp[MAX_SIZE];
	 int	nsize;
	 int	head;

	ft_stk_arr_head(*a, tmp, ft_find_head(*a));
	osize = ft_lis_length(tmp, a->size);
	mvs->sa(a, NULL);
	head = ft_find_head(*a);
	ft_stk_arr_head(*a, tmp, head);
	nsize = ft_lis_length(tmp, a->size);
	mvs->sa(a, NULL);
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
	int	size;

	head = ft_find_head(*(param->a));
	if (ft_check_swap(param->a, param->mvs, &head) && printf("swap\n"))
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
	i = 0;
	printf("this is the head %d\n", head);
	ft_printstack(param->a);
	ft_stk_arr_head(*(param->a), keys, head);
	ft_putstr_fd("arr head : ", 1);
	ft_printarr(keys, param->a->size, 1);
	ft_find_lis(keys, lis, param->a->size);
	ft_putstr_fd("arr lis : ", 1);
	ft_printarr(lis, param->a->size, 1);
	while (i < param->a->size)
	{
		size = param->a->size - 1;
		printf("this is the top2 : %d\n", ft_getindex(*(param->a), size));
		if (ft_indexOf(lis, param->a->size, ft_getindex(*(param->a), size)) == -1 && i-- && printf("move this %d\n", ft_getindex(*(param->a), size)) )
			ft_catchar(param->str, param->mvs->pb(param->a, param->b));
		ft_putstr_fd("**********************\n", 1);
		ft_printboth(param->a, param->b);
		printf("this is the top : %d\n", ft_getindex(*(param->a), size));
		ft_catchar(param->str, param->mvs->rra(param->a, param->b));
		i++;
	}
}

void	ft_solve_big(t_param *param)
{
	ft_push_to_b(param);
	ft_push_to_a(param);
}
