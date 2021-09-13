#include "../push_swap.h"

static void ft_swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void ft_quicksort(int* arr,int first,int last)
{
	int i;
	int j;
	int	pivot;

   if (first<last)
   {
	   pivot=first;
	   i=first;
	   j=last;
		while (i<j)
		{
			while(arr[i]<=arr[pivot]&&i<last)
				i++;
			while(arr[j]>arr[pivot])
				j--;
			if(i<j)
				ft_swap(arr, i, j);
    	}
	ft_swap(arr, pivot, j);
    ft_quicksort(arr,first,j-1);
    ft_quicksort(arr,j+1,last);
   }
}

void ft_stkdup(t_stack stk, t_stack *dup)
{
	int 	head;
	int 	tail;

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

void ft_sorted_arr(t_stack stk, int *arr)
{
	int		i;
	t_stack tmp;

	if (arr == NULL)
		return ;
	ft_bzero(arr, MAX_SIZE * sizeof(int));
	ft_stkdup(stk, &tmp);
	i = 0;
	while (ft_isempty(&tmp) == 0)
		arr[i++] = ft_pop(&tmp);
	ft_quicksort(arr, 0, stk.size - 1);	
}

int		ft_equstack(t_stack a, t_stack b)
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

int		ft_getindex(t_stack a, int index)
{
	return (a.arr[(a.head + index) % MAX_SIZE]);
}
