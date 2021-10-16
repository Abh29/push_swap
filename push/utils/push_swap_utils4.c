#include "../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n--)
		*str++ = 0;
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!dst && !src)
		return (0);
	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	if (src > dst)
	{
		while (len--)
			*str2++ = *str1++;
		len--;
	}
	else
	{
		str1 += len - 1;
		str2 += len - 1;
		while (len--)
			*str2-- = *str1--;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len--)
		*str++ = (unsigned char)c;
	return (b);
}
