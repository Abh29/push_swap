#include "../push_swap.h"
long ss = 0;

typedef struct s_bfs
{
	t_list	*history;
	t_list	*queue;
	t_stack	origina;
	t_stack originb;
	t_Hnode	*final;
	int		step;
}				t_bfs;


static int		ft_look_history(t_bfs bfs, t_stack a, t_stack b)
{
	t_Hnode *newQ;
	t_Hnode *tmp;
	t_list	*history;

	newQ = ft_newHnode(a, b, 0);
	history = bfs.history;
	while (history)
	{
		tmp = (t_Hnode *)history->content;
		if (ft_eqlHNode(&bfs.origina, &bfs.originb, tmp, newQ) == 1)
			return (1);
		history = history->next;
	}
	return (0);
}

static void	ft_add_node(t_bfs *bfs, t_Hnode current, t_move *mv)
{
	t_Hnode *newElm;
	char	s;

	s = mv(&(current.a), &(current.b));
	newElm = ft_newHnode(current.a, current.b, 0);
	ft_catchar(newElm->str, s);
	if (ft_look_history(*bfs, current.a, current.b) == 0)
	{
		//ft_putstr_fd("\npushing to &(bfs->queue) !&(bfs-> \n", 1));
		//ft_putlnbr_fd(ss++, 1);
		ft_Qpush(&(bfs->queue), ft_lstnew(newElm));
		ft_Qpush(&(bfs->history), ft_lstnew(newElm));
	}
	newElm->step = current.step + 1;

	return ;
}

static int	ft_add_nodes(t_bfs *bfs, t_Hnode *current, t_moves mvs)
{
	ft_add_node(bfs, *current, mvs.pa);
	ft_add_node(bfs, *current, mvs.pb);
	ft_add_node(bfs, *current, mvs.ra);
	ft_add_node(bfs, *current, mvs.rb);
	ft_add_node(bfs, *current, mvs.rr);
	ft_add_node(bfs, *current, mvs.rra);
	ft_add_node(bfs, *current, mvs.rrb);
	ft_add_node(bfs, *current, mvs.rrr);
	ft_add_node(bfs, *current, mvs.sa);
	ft_add_node(bfs, *current, mvs.sb);
	ft_add_node(bfs, *current, mvs.ss);
	return (0);
}

static t_Hnode *ft_finalNode(t_stack a)
{
	int		tmp[MAX_SIZE];
	t_Hnode *out;
	int 	i;

	out = (t_Hnode *)malloc(sizeof(t_Hnode));
	if (out == NULL)
		ft_exit("Error : malloc error !\n", 2);
	out->b = ft_newstack();
	ft_sorted_arr(a, tmp);
	i = 0;
	while (i < a.size)
	{
		ft_push(&(out->a), tmp[i++]);
	}
	out->hash = ft_hashcode_node(out->a, out->b);
	return (out);
}

t_bfs *ft_newbfs()
{
	t_bfs *out;

	out = (t_bfs *)malloc(sizeof(t_bfs));
	if (out == NULL)
		ft_exit("Error : malloc error !\n", 2);
	out->queue = NULL;
	out->history = NULL;
	out->final = NULL;
	out->step = 0;
	return (out);
}

t_Hnode	*ft_bfs(t_stack a, t_stack b, t_moves mvs)
{
	t_bfs	*bfs;
	t_list	*tmp;

	bfs = ft_newbfs();
	bfs->final = ft_finalNode(a);
	bfs->origina = a;
	bfs->originb = b;
	ft_Qpush(&(bfs->queue),ft_lstnew(ft_newHnode(a, b, bfs->step)));
	ft_Qpush(&(bfs->history), ft_lstnew(ft_newHnode2(a, b, bfs->step)));
	tmp = NULL;
	while (bfs->queue != NULL)
	{
		tmp = ft_Qpop(&(bfs->queue));
		// printf("we are in %p\n", tmp);
		ft_printHnode((t_Hnode*)tmp->content);
	//	getchar();
		// t_Hnode *content = (t_Hnode *) tmp->content;
		// ft_putstr_fd("moves : ", 1);
		// ft_putstr_fd(content->str->str, 1);
		// ft_putstr_fd("\n", 1);
		if (ft_eqlHnode(tmp->content, bfs->final) == 1)
			break ;
		bfs->step = ft_add_nodes(bfs, (t_Hnode *)tmp->content, mvs);
		free(tmp->content);
		free(tmp);
	}
	// free &(bfs->queue) ?&(bfs->?!
	//f)t_lstclear(&s_history, free);
	return ((t_Hnode*)tmp->content);
}



