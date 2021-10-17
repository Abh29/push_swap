#include "libft.h"

int	ft_binary_sisze(int a)
{
	int out;
	int i;

	out = 0;
	i = 0;
	while (a >> i)
		out++;
	return (out);
}
