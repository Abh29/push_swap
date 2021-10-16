/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:38:02 by mehill            #+#    #+#             */
/*   Updated: 2021/10/16 22:26:12 by mehill           ###   ########.fr       */
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
/*
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

*/

int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

static int	ft_helper(int *arr, int *index, int *LIS, int n)
{
	int	i;
	int	lis_length;

	i = 0;
	lis_length = -1;
	while (i < n)
	{
		index[i] = search_replace(LIS, 0, i, arr[i]);
		if (lis_length < index[i])
			lis_length = index[i];
		i++;
	}
	return (lis_length);
}

void	ft_find_lis(int arr[], int lis[], int n)
{
	int	i;
	int	lis_length;
	int	LIS[MAX_SIZE];
	int	index[MAX_SIZE];

	i = 0;
	while (i < n)
	{
		LIS[i] = INT_MAX;
		lis[i++] = -1;
	}
	ft_memset(index, 0, MAX_SIZE * sizeof(int));
	LIS[0] = arr[0];
	lis_length = ft_helper(arr, index, LIS, n);
	i = n;
	while (i >= 0)
	{
		if (index[i] == lis_length)
		{
			lis[lis_length] = arr[i];
			--lis_length;
		}
		i--;
	}
}
