/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:34:32 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 15:34:35 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_rra(t_stack *a, t_stack *b)
{
	int	elm;

	if (!a || !b || a->size < 2)
		return (0);
	(void) b;
	elm = ft_popbottom(a);
	ft_push(a, elm);
	return ('i');
}

char	ft_rrb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_rra(b, a);
	return ('j');
}

char	ft_rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_rra(a, b);
	ft_rrb(a, b);
	return ('k');
}
