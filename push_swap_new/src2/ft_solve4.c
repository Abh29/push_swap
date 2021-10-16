/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:38:02 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 17:14:20 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_shift_arr(int arr[], int n)
{
	int	first;
	int	i;

	first = arr[0];
	i = 0;
	while (i < n - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = first;
}

void	ft_find_lis(int arr[], int lis[], int n)
{
	int	i;
	int	j;
	int	k;
	int	last_min;
	int	tmp;

	i = 0;
	k = 0;
	j = ft_lis_length(arr, n);
	last_min = -1;
	while (i < n)
	{
		tmp = arr[0];
		arr[0] = -1;
		ft_shift_arr(arr, n);
		if (ft_lis_length(arr, n - i) <= j && tmp > last_min)
		{
			lis[k++] = tmp;
			last_min = tmp;
			j--;
		}
		i++;
	}
	while (k < n)
		lis[k++] = -1;
}
