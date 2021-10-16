/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:43:32 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 15:43:54 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stkdup(t_stack stk, t_stack *dup)
{
	int	head;
	int	tail;

	*dup = ft_newstack();
	head = stk.head;
	tail = stk.tail;
	while (head != tail)
	{
		ft_push(dup, stk.arr[head++]);
		if (head >= MAX_SIZE)
			head = 0;
	}
}

void	ft_sorted_arr(t_stack stk, int *arr)
{
	if (arr == NULL)
		return ;
	ft_stk_to_arr(stk, arr);
	ft_quicksort(arr, 0, stk.size - 1);
}

void	ft_stk_to_arr(t_stack stk, int *arr)
{
	int		i;
	t_stack	tmp;

	if (arr == NULL)
		return ;
	ft_bzero(arr, MAX_SIZE * sizeof(int));
	ft_stkdup(stk, &tmp);
	i = 0;
	while (ft_isempty(&tmp) == 0)
		arr[i++] = ft_pop(&tmp);
}

int	ft_equstack(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	if (a.size != b.size)
		return (0);
	while (i < a.size)
	{
		if (ft_getindex(a, i) != ft_getindex(b, i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_getindex(t_stack a, int index)
{
	int	arr[MAX_SIZE];
	
	if (index < 0 || index >= a.size)
		return (-1);
	ft_stk_to_arr(a, arr);
	return (arr[index]);
}
