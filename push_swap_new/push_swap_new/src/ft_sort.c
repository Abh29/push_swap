#include "../push_swap.h"

void	ft_swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	ft_quicksort(int* arr,int first,int last)
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

int		ft_binarySearch(int *arr, int left, int right, int key)
{
	int mid;

	if (arr == NULL)
		return (-1);
    if (right >= left) {
        mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return ft_binarySearch(arr, left, mid - 1, key);
        return ft_binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int		ft_indexOf(int *arr, int size, int key)
{
	int out;

	if (arr == NULL)
		return (-1);
	out = -1;
	while (++out < size)
	{
		if (arr[out] == key)
			return (out);
	}
	return (-1);
}
