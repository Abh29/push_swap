#include "../push_swap.h"


void	ft_fill_info(t_solve *info, t_stack *a, t_stack *b);
void	ft_stepi(t_solve *info, t_move *mv, int i, t_string *str);


void	ft_solveS(t_solve *info, t_moves *mvs, t_string *str)
{
	int			desc;

	desc = info->idxA[0] * 100 + info->idxA[1] * 10 + info->idxA[2];
	if (desc == 12)
		return ;
	if (desc == 21)
	{
		ft_stepi(info, mvs->sa, 1, str);
		ft_stepi(info, mvs->ra, 1, str);
	}
	else if (desc == 102)
		ft_stepi(info, mvs->sa, 1, str);
	else if (desc == 120)
		ft_stepi(info, mvs->rra, 1, str);
	else if (desc == 201)
		ft_stepi(info, mvs->ra, 1, str);
	else if (desc == 210)
	{
		ft_stepi(info, mvs->sa, 1, str);
		ft_stepi(info, mvs->rra, 1, str);
	}
}

void	ft_solveM(t_solve *info, t_moves *mvs, t_string *str)
{
	ft_stepi(info, mvs->pb, 2, str);
	ft_solveS(info, mvs, str);

}

void	ft_fill_info(t_solve *info, t_stack *a, t_stack *b)
{
	int	arr[MAX_SIZE];
	int	ord[MAX_SIZE];

	info->a = a;
	info->b = b;
	info->sizeA = 0;
	ft_stk_to_arr(*a, arr);
	ft_sorted_arr(*a, ord);
	while (info->sizeA < a->size)
	{
		info->idxA[info->sizeA] = ft_indexOf(arr, a->size, ord[info->sizeA]);
		info->sizeA++;
	}
	info->sizeB = 0;
	ft_stk_to_arr(*b, arr);
	ft_sorted_arr(*b, ord);
	while (info->sizeB < b->size)
	{
		info->idxB[info->sizeB] = ft_indexOf(arr, b->size, ord[info->sizeB]);
		info->sizeB++;
	}	
}

void	ft_stepi(t_solve *info, t_move *mv, int i, t_string *str)
{
	char	c;

	while (i-- > 0)
	{
		c = mv(info->a, info->b);
		ft_catchar(str, c);
	}
}

int		ft_getpos(t_stack *a, int elm)
{
	int i;
	int e;

	if (ft_isempty(a) || a->size < 2)
		return (0);
	i = 0;
	while (i < a->size)
	{
		e = ft_getindex(*a, i);
		if (elm < e)
			break;
		i++;
	}
	return (a->size - i); 
}

void	ft_turnB(t_solve *info, int elm, t_string *str, t_moves *mvs)
{
	int i;
	
	i = ft_getpos(info->b, elm);
	printf("this is the position %d\n",i);
	if (i > 0)
		ft_stepi(info, mvs->rb, i, str);
	if (i < 0)
		ft_stepi(info, mvs->rrb, -i, str);
	ft_stepi(info, mvs->pb, 1, str);
	if (info->b->size == 2 && ft_issorted(info->b, DEC))
	{
		printf("here!\n");
		ft_stepi(info, mvs->sb, 1, str);
	}	
}

void	ft_solveL(t_stack *a, t_stack *b, t_moves *mvs)
{
	t_solve		info;
	t_string	*str;
	int			elm;

	ft_fill_info(&info, a, b);
	str = ft_newString(1000);
	while (ft_isempty(info.a) == 0)
	{
		elm = ft_getindex(*(info.a), info.a->size - 1);
		ft_turnB(&info, elm, str, mvs);
		ft_printboth(a, b);
		printf("%d\n",elm);
	}
}
