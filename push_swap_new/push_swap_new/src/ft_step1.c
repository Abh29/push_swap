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
	int lis[MAX_SIZE];
	int keys[MAX_SIZE];

	head = ft_find_head(*(param->a));
	if (ft_check_swap(param->a, param->mvs, &head))
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
	i = 0;
	ft_stk_arr_head(*(param->a), keys, head);
	ft_find_lis(keys, lis, param->a->size);
	while (i < param->a->size)
	{
		if (ft_indexOf(lis, param->a->size, ft_getindex(*(param->a), 0)) == -1)
			ft_catchar(param->str, param->mvs->pb(param->a, param->b));
		ft_catchar(param->str, param->mvs->ra(param->a, param->b));
		i++;
	}
}

void	ft_solve_big(t_param *param)
{
	ft_push_to_b(param);
	ft_push_to_a(param);
}