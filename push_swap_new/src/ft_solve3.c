/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:36:50 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 17:13:29 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stk_arr_head(t_stack stk, int *arr, int head)
{
	t_stack dup;
	int	i;
	int	j;

	ft_stkdup(stk, &dup);
	i = 0;
	while (ft_getindex(dup, 0) != head && i++ < stk.size + 1)
	{
		j = ft_popbottom(&dup);
		ft_push(&dup, j);
	}
	ft_stk_to_arr(dup, arr);
}

static int	ft_lis(int arr[], int n, int *max)
{
	int	res;
	int	here;
	int	i;

	if (n == 1)
		return (1);
	here = 1;
	i = 1;
	while (i < n)
	{
		res = ft_lis(arr, i, max);
		if (arr[i - 1] < arr[n - 1] && res + 1 > here)
			here = res + 1;
		i++;
	}
	if (*max < here)
		*max = here;
	return (here);
}

int	ft_lis_length(int arr[], int n)
{
	int	max;

	max = 1;
	ft_lis(arr, n, &max);
	return (max);
}

int	ft_find_head(t_stack a)
{
	int	i;
	int	tmp[MAX_SIZE];
	int	head;
	int	max_l;

	i = 0;
	head = 0;
	max_l = 0;
	while (i < a.size)
	{
		ft_stk_arr_head(a, tmp, ft_getindex(a, i));
		if (ft_lis_length(tmp, a.size) > max_l)
		{
			max_l = ft_lis_length(tmp, a.size);
			head = i;
		}
		i++;
	}
	return (ft_getindex(a, head));
}
