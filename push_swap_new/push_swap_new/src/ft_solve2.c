#include "../push_swap.h"

int		ft_subarr_size(int *keys, int size, int head)
{
	int i;
	int j;
	int	out;

	i = 0;
	j = ft_indexOf(keys, size, head);
	out = 1;
	while (i < size)
	{
		if (keys[j % size] > head)
		{
			head = keys[j % size];
			out++;
		}
		i++;
		j++;
	}
	return (out);
}

int		ft_get_head_markup(t_stack *a)
{
	int		head;
	int		max;
	int		keys[MAX_SIZE];
	int		i;

	ft_stk_to_arr(*a, keys);
	i = 0;
	head = keys[0];
	max = ft_subarr_size(keys, a->size, keys[0]);
	while (i < a->size)
	{
		if (ft_subarr_size(keys, a->size, keys[i]) > max)
		{
			head = keys[i];
			max = ft_subarr_size(keys, a->size, head);
		}
		i++;
	}
	return (head);
}

int	ft_check_swap(t_stack *a, t_moves *mvs, int *last_head)
{
	 int	osize;
	 int	keys[MAX_SIZE];
	 int	new_head;

	ft_stk_to_arr(*a, keys);
	osize = ft_subarr_size(keys, a->size, *last_head);
	mvs->sa(a, NULL);
	new_head = ft_get_head_markup(a);
	if (new_head != *last_head)
	{
		ft_swap(keys, 0, 1);
		if (osize > ft_subarr_size(keys, a->size, new_head))
		{
			*last_head = new_head;
			return (1);
		}
	}
	mvs->sa(a, NULL);
	return (0);
}

void	ft_get_marked(int *keys, int *marked, int size, int head)
{
	int i;
	int j;

	i = 0;
	j = ft_indexOf(keys, size, head);
	ft_bzero(marked, size * sizeof(int));
	while (i < size)
	{
		if (keys[j % size] > head)
		{
			head = keys[j % size];
			marked[j % size] = 1;
		}
		i++;
		j++;
	}
}

void	ft_push_to_A(t_param *param)
{
	int	head;
	int	i;
	int marked[MAX_SIZE];
	int keys[MAX_SIZE];

	head = ft_get_head_markup(param->a);
	if (ft_check_swap(param->a, param->mvs, &head))
		ft_catchar(param->str, param->mvs->sa(param->a, param->b));
	i = 0;
	ft_stk_to_arr(*(param->a), keys);
	ft_get_marked(keys, marked, param->a->size, head);
	printf("this is head %d\n", head);
	while (i < param->a->size)
	{
		if (marked[i])
		{
			ft_catchar(param->str, param->mvs->pb(param->a, param->b));
		}
		ft_catchar(param->str, param->mvs->ra(param->a, param->b));
		i++;
	}
}

void	ft_solve_big(t_param *param)
{
	ft_push_to_A(param);
}