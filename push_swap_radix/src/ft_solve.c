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

void	ft_solve_xs(t_param *param)
{
	if (param->a->size == 1)
		return ;
	if (ft_issorted(param->a, ACC))
		return ;
	ft_catchar(param->str, param->mvs->sa(param->a, param->b));
}

void	ft_solve_s(t_param *param)
{
	int	desc;
	int	arr[MAX_SIZE];

	ft_stk_to_arr(*(param->a), arr);
	desc = arr[0] * 100 + arr[1] * 10 + arr[2];
	if (desc == 123)
		return ;
	if (desc == 132)
	{
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
		ft_catchar(param->str, param->mvs->ra(param->a, param->b));
	}
	else if (desc == 213)
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
	else if (desc == 231)
		ft_catchar(param->str, param->mvs->rra(param->a, param->b));
	else if (desc == 312)
		ft_catchar(param->str, param->mvs->ra(param->a, param->b));
	else if (desc == 321)
	{
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
		ft_catchar(param->str, param->mvs->rra(param->a, param->b));
	}
}

void	ft_solve_xm(t_param *param)
{
	t_move	*mv;
	int		keys[MAX_SIZE];

	ft_stk_to_arr(*(param->a), keys);
	if (ft_indexOf(keys, param->a->size, 4) > 1)
		mv = param->mvs->rra;
	else
		mv = param->mvs->ra;
	while (ft_getindex(*(param->a), 0) != 4)
		ft_catchar(param->str, mv(param->a, param->b));
	ft_catchar(param->str, param->mvs->pb(param->a, param->b));
	ft_solve_s(param);
	ft_catchar(param->str, param->mvs->pa(param->a, param->b));
	ft_catchar(param->str, param->mvs->ra(param->a, param->b));
}

// void	ft_solve_l(t_param *param)
// {
// 	int i;
// 	int j;
// 	int size;

// 	i = 0;
// 	size = param->a->size;
// 	while (size >> i)
// 	{
// 		j = 0;
// 		printf("***we have %d***\n",i);
// 		ft_printboth(param->a, param->b);
// 		while (j < size)
// 		{
// 			if (ft_getindex(*(param->a), 0) >> i & 1)
// 			{
// 				ft_catchar(param->str, param->mvs->ra(param->a, param->b));
// 				if (param->a->size == size && ft_issorted(param->a, ACC))
// 					break ;
// 			}
// 			else
// 				ft_catchar(param->str, param->mvs->pb(param->a, param->b));
// 			j++;
// 			printf("***inside ***\n");
// 			ft_printboth(param->a, param->b);
// 			getchar();
// 		}
// 		printf("***pushing***\n");
// 		ft_printboth(param->a, param->b);	
// 		while (ft_isempty(param->b) == 0)
// 			ft_catchar(param->str, param->mvs->pa(param->a, param->b));
// 		printf("*** pushing back ***\n");
// 		ft_printboth(param->a, param->b);
// 		i++;
// 		getchar();
// 	}
// }


void	ft_solve_l(t_param *param)
{
	int i;
	int j;
	int size;

	i = 0;
	size = param->a->size;	
//	printf("\n\n\n");
//	ft_printboth(param->a, param->b);
	while (size >> i)
	{
		j = 0;
		while (j < size)
		{
			if (ft_getindex(*(param->a), 0) >> i & 1)
			{
				ft_catchar(param->str, param->mvs->ra(param->a, param->b));
				if (param->a->size == size && ft_issorted(param->a, ACC))
					break ;
			}
			else
				ft_catchar(param->str, param->mvs->pb(param->a, param->b));
			j++;
		}
	//	printf("\n\n\n");
	//	ft_printboth(param->a, param->b);
		while (ft_isempty(param->b) == 0)
			ft_catchar(param->str, param->mvs->pa(param->a, param->b));
		// printf("\n\n\n");
		// ft_printboth(param->a, param->b);
		// getchar();
		if (ft_issorted(param->a, ACC))
			break ;
		i++;
	}
}


void	ft_solve(t_param *param)
{
	if (ft_issorted(param->a, ACC))
		return ;
	else if (param->a->size < 3)
		ft_solve_xs(param);
	else if (param->a->size == 3)
		ft_solve_s(param);
	else if (param->a->size == 4)
		ft_solve_xm(param);
	else if (param->a->size == 5)
		ft_solve_m(param);
	else
		ft_solve_l(param);
}
