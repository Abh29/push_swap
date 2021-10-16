#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*l;

	if (*lst)
	{
		l = ft_lstlast(*lst);
		l->next = new;
	}
	else
		*lst = new;
}

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}
