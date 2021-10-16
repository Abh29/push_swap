#include "../push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

long	ft_atoi(const char *str, t_stack *s)
{
	long	neg;
	long	res;

	res = 0;
	neg = 1;
	while (*str == 32 || *str == '\n' || *str == '\f' \
		|| *str == '\v' || *str == '\r' || *str == '\t')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		error_close(s);
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (((int)*str++) - 48);
	if (*str)
	{
		if (*str != ' ')
			error_close(s);
	}
	if ((res * neg) > 2147483647 || (res * neg) < -2147483648)
		error_close(s);
	return (res * neg);
}

t_list	*ft_lstnew(int num, t_stack *s)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		error_close(s);
	elem->num = num;
	elem_init(elem);
	return (elem);
}
