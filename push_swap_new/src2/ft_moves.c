/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:33:42 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 15:34:09 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_sa(t_stack *a, t_stack *b)
{
	int	c;
	int	idx1;
	int	idx2;

	if (!a || a->size < 2)
		return (0);
	(void) b;
	idx1 = (a->tail + MAX_SIZE - 1) % MAX_SIZE;
	idx2 = (idx1 + MAX_SIZE - 1) % MAX_SIZE;
	c = a->arr[idx1];
	a->arr[idx1] = a->arr[idx2];
	a->arr[idx2] = c;
	return ('a');
}

char	ft_sb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_sa(b, a);
	return ('b');
}

char	ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_sa(a, b);
	ft_sb(a, b);
	return ('c');
}
