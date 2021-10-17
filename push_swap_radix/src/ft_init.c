/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:32:28 by mehill            #+#    #+#             */
/*   Updated: 2021/10/17 00:47:22 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init(t_moves *mvs)
{
	mvs->sa = &ft_sa;
	mvs->sb = &ft_sb;
	mvs->ss = &ft_ss;
	mvs->pa = &ft_pa;
	mvs->pb = &ft_pb;
	mvs->ra = &ft_ra;
	mvs->rb = &ft_rb;
	mvs->rr = &ft_rr;
	mvs->rra = &ft_rra;
	mvs->rrb = &ft_rrb;
	mvs->rrr = &ft_rrr;
}

void	ft_exit(char *msg, int err)
{
	ft_putstr_fd(msg, 2);
	exit(err);
}

int	ft_is_simp_number(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
}

void	ft_read_args(int argc, char **argv, t_stack *a)
{
	int		i;
	long	num;
	int		tmp[MAX_SIZE];

	i = argc - 1;
	while (i > 0)
	{
		if (ft_is_simp_number(argv[i]) == 0)
			ft_exit("Error : argument is NOT a positif INTEGER !\n", 1);
		num = ft_atol(argv[i--]);
		if (num > INT_MAX)
			ft_exit("Error : argument is bigger than MAX_INT !\n", 1);
		ft_push(a, (int)num);
	}
	ft_sorted_arr(*a, tmp);
	i = 0;
	while (i < argc - 1)
	{
		if (tmp[i] == tmp[i + 1])
			ft_exit("Error : arguments are duplicated !\n", 1);
		i++;
	}
}
