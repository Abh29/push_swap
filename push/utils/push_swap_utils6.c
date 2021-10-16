#include "../push_swap.h"

static int	ft_str_size_count(char const *s, char c, int issize)
{
	int	str_size;
	int	str_count;
	int	word_flag;

	if (issize == 1)
	{
		str_size = 0;
		while (*s && *s++ != c)
			str_size++;
		return (str_size);
	}
	str_count = 0;
	if (*s == 0)
		return (0);
	while (*s)
	{
		word_flag = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s++ != c)
			word_flag = 1;
		if (word_flag == 1)
			str_count++;
	}
	return (str_count);
}

static void	ft_free_str(char **str)
{
	while (*str)
	{
		free(*str);
		*str++ = NULL;
	}
	free(str);
	str = NULL;
}

char 	**ft_main_loop(char **res, char const *s, char c, int str_num)
{
	int	str_size;
	int	str_pos;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			return (res);
		str_size = ft_str_size_count(s, c, 1);
		res[str_num] = (char *)malloc(sizeof(char) * str_size + 1);
		if (!res[str_num])
		{
			ft_free_str(res);
			return (NULL);
		}
		res[str_num][str_size] = 0;
		str_pos = 0;
		while (str_pos < str_size)
			res[str_num][str_pos++] = *s++;
		str_num++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)

{
	char	**res;
	int		str_count;
	int		str_num;

	str_num = 0;
	if (!s)
		return (NULL);
	str_count = ft_str_size_count(s, c, 0);
	res = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!res)
		return (NULL);
	res[str_count] = NULL;
	res = ft_main_loop(res, s, c, str_num);
	return (res);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(lst);
		lst = NULL;
	}
	lst = NULL;
}
