#include "push_swap.h"

void	error_close(t_stack *s)
{
	s->error = 1;
	push_swap_close(s);
}

static void	ac_check(int ac, t_stack *s)
{
	if (ac == 1)
	{
		free(s);
		s = NULL;
		exit(0);
	}
}

static int	symbol_check(t_stack *s, char **av, int i)
{
	int	j;
	int	digit_flag;

	j = -1;
	while (av[i][++j])
	{
		if (ft_isdigit(av[i][j]))
			digit_flag = 1;
		else if (av[i][j] != ' ' && av[i][j] != '-')
			error_close(s);
	}
	return (digit_flag);
}

static char	*seq_fil(int i, t_stack *s, char **av, char *seq_str)
{
	char	*tmp;

	tmp = ft_strjoin(seq_str, " ");
	free(seq_str);
	if (!tmp)
		error_close(s);
	seq_str = tmp;
	tmp = ft_strjoin(seq_str, av[i]);
	free(seq_str);
	if (!tmp)
		error_close(s);
	seq_str = tmp;
	return (seq_str);
}

void	seq_validation(t_stack *s, int ac, char **av)
{
	int		i;
	int		digit_flag;
	char	*seq_str;

	i = 0;
	digit_flag = 0;
	seq_str = NULL;
	ac_check(ac, s);
	while (av[++i])
	{
		digit_flag = symbol_check(s, av, i);
		if (!digit_flag)
			error_close(s);
		if (!seq_str)
		{
			seq_str = ft_strdup(av[i]);
			if (!seq_str)
				error_close(s);
		}
		else
			seq_str = seq_fil(i, s, av, seq_str);
	}
	s->seq = seq_str;
}
