/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:46:55 by mehill            #+#    #+#             */
/*   Updated: 2021/10/15 15:47:23 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_string	*ft_newString(int max_l)
{
	t_string	*out;

	if (max_l < 1)
		return (NULL);
	out = malloc(sizeof(t_string));
	if (out == NULL)
		return (NULL);
	out->str = malloc(max_l + 1);
	if (out->str == NULL)
	{
		free(out);
		return (NULL);
	}
	*(out->str) = 0;
	out->max_l = max_l;
	out->length = 0;
	return (out);
}

int	ft_catchar(t_string *s, char c)
{
	char	*tmp;

	if (s->length == s->max_l)
	{
		tmp = malloc(s->max_l * 2 + 1);
		if (tmp == NULL)
			return (0);
		*tmp = 0;
		ft_strlcpy(tmp, s->str, s->length);
		free(s->str);
		s->str = tmp;
		s->max_l *= 2;
	}
	s->str[s->length++] = c;
	s->str[s->length] = 0;
	return (1);
}

int	ft_catstr(t_string *s, char *str)
{
	while (*str)
	{
		if (ft_catchar(s, *str) == 0)
			return (0);
		str++;
	}
	return (1);
}

char	ft_charAt(t_string s, int index)
{
	return (s.str[index]);
}

void	ft_freeString(t_string **str)
{
	if (str == NULL)
		return ;
	if (*str)
	{
		free((*str)->str);
		free(*str);
		*str = NULL;
	}
	return ;
}
