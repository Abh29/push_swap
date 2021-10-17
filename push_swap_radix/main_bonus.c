#include "push_swap.h"

t_move	*ft_get_move2(t_moves *mvs, char *line)
{
	if (ft_strncmp(line, "rr\n", 3) == 0)
		return (mvs->rr);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (mvs->pa);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (mvs->pb);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		return (mvs->rra);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		return (mvs->rrb);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		return (mvs->rrr);
	return (NULL);
}

t_move	*ft_get_move(t_moves *mvs, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (mvs->sa);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (mvs->sb);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (mvs->ss);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (mvs->ra);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (mvs->rb);
	return (ft_get_move2(mvs, line));
}

void	ft_check(t_param *param)
{
	char	*line;
	t_move	*mv;

	line = get_next_line(0);
	while (line)
	{
		if (*line == '\n')
			break ;
		mv = ft_get_move(param->mvs, line);
		if (mv == NULL)
			ft_exit("Error\n", 1);
		mv(param->a, param->b);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (ft_issorted(param->a, ACC) && ft_isempty(param->b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_moves	mvs;
	t_stack	a;
	t_stack	b;
	t_param	param;

	if (argc == 1)
		return (0);
	ft_init(&mvs);
	a = ft_newstack();
	b = ft_newstack();
	ft_read_args(argc, argv, &a);
	ft_replace_args(&a);
	param.a = &a;
	param.b = &b;
	param.mvs = &mvs;
	ft_check(&param);
	return (0);
}