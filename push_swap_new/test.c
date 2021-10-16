#include <stdio.h>
#include <stdlib.h>

static int ft_lis(int arr[], int n, int* max)
{
	int res;
	int here;
	int i;

    if (n == 1)
        return 1;
	here = 1;
	i = 1;
	while (i < n)
	{
		res = ft_lis(arr, i, max);
        if (arr[i - 1] < arr[n - 1] && res + 1 > here)
            here = res + 1;
		i++;
	}
    if (*max < here)
        *max = here;
    return (here);
}
 
int ft_lis_length(int arr[], int n)
{
    int max;

	max = 1;
    ft_lis(arr, n, &max);
    return (max);
}
void	ft_shift_arr(int arr[], int n)
{
	int first;
	int i;

	first = arr[0];
	i = 0;
	while (i < n - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = first;
}
void ft_print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void ft_find_lis(int arr[],int lis[], int n)
{
	int i;
	int j;
	int k;
	int last_min;
	int	tmp;

	i = 0;
	k = 0;
	j = ft_lis_length(arr, n);
	last_min = -1;
	while (i < n)
	{
		tmp = arr[0];
		arr[0] = -1;
		ft_shift_arr(arr, n);
		if (ft_lis_length(arr, n - i) <= j && tmp > last_min)
		{
			lis[k++] = tmp;
			last_min = tmp;
			j--;
		}
		i++;
	}
}

 
int main()
{
    int arr[] = { 10, 9, 22, 33, 21, 50, 41, 60 };
	int lis[10] = {-1};
    int n = sizeof(arr) / sizeof(arr[0]);
	int size = ft_lis_length(arr, n);
    printf("Length of lis is %d\n",
           size);
	ft_find_lis(arr, lis, 8);
	ft_print_arr(lis, size);
    return 0;
}