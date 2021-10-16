#include "../push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size_all;
	char	*res_tmp;

	if (!s1 || !s2)
		return (NULL);
	size_all = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size_all + 1));
	if (!res)
		return (0);
	res[size_all] = 0;
	res_tmp = res;
	ft_memset(res, '0', size_all);
	ft_memmove(res, s1, ft_strlen(s1));
	res_tmp += ft_strlen(s1);
	ft_memmove(res_tmp, s2, ft_strlen(s2));
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr)
		ft_bzero(ptr, sizeof(char) * (size + 1));
	return (ptr);
}
