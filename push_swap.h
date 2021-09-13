#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

#define MAX_SIZE 600

typedef struct s_stack
{
	int	arr[MAX_SIZE];
	int	head;
	int tail;
	int size;
}				t_stack;

typedef char t_move(t_stack *a, t_stack *b);

typedef struct s_moves
{
	t_move	*sa;
	t_move	*sb;
	t_move	*ss;
	t_move	*pa;
	t_move	*pb;
	t_move	*ra;
	t_move	*rb;
	t_move	*rr;
	t_move	*rra;
	t_move	*rrb;
	t_move	*rrr;
}				t_moves;

typedef struct s_string
{
	char	*str;
	int		length;
	int		max_l;
}				t_string;

typedef struct s_history2
{
	long	hash;
	char	*moves[MAX_SIZE];
	t_string *str;
	int		step;
}				t_Hnode2;

typedef struct s_history
{
	t_stack	a;
	t_stack	b;
	long	hash;
	char	*moves[MAX_SIZE];
	t_string *str;
	int		step;
}				t_Hnode;



#define ACC 1
#define DEC 2

/**** stack ******/
t_stack ft_newstack();
void	ft_push(t_stack *s, int elm);
int		ft_pop(t_stack *s);
int		ft_isempty(t_stack *s);
int		ft_find(t_stack *s, int elm);
int		ft_issorted(t_stack *s, int ord);
int		ft_isfull(t_stack *s);
void	ft_pushbottom(t_stack *s, int elm);
int		ft_popbottom(t_stack *s);
void	ft_quicksort(int* arr,int first,int last);
void	ft_stkdup(t_stack stk, t_stack *dup);
void	ft_sorted_arr(t_stack stk, int *arr);
int		ft_getindex(t_stack a, int index);
int		ft_equstack(t_stack a, t_stack b);

/*****************/

/***** moves *****/
char	ft_sa(t_stack *a, t_stack *b);
char	ft_sb(t_stack *a, t_stack *b);
char 	ft_ss(t_stack *a, t_stack *b);
char	ft_ra(t_stack *a, t_stack *b);
char	ft_rb(t_stack *a, t_stack *b);
char 	ft_rr(t_stack *a, t_stack *b);
char	ft_rra(t_stack *a, t_stack *b);
char	ft_rrb(t_stack *a, t_stack *b);
char	ft_rrr(t_stack *a, t_stack *b);
char	ft_pa(t_stack *a, t_stack *b);
char	ft_pb(t_stack *a, t_stack *b);

/****************/

void	ft_init(t_moves *mvs);
void	ft_exit(char *msg, int err);
int		ft_is_simp_number(char *str);
void	ft_read_args(int argc, char **argv, t_stack *a);

char		ft_charAt(t_string s, int index);
int			ft_catstr(t_string *s, char *str);
int			ft_catchar(t_string *s, char c);
t_string	*ft_newString(int max_l);
void		ft_freeString(t_string **str);

void	ft_printstack(t_stack *a);
void	ft_printboth(t_stack *a, t_stack *b);
void	ft_printarr(int *arr, int size, int fd);
void	ft_printHnode(t_Hnode *hnode);

int		ft_eqlHNode(t_stack *origina, t_stack *originb, t_Hnode *a, t_Hnode *b);
void	ft_getstacks(t_Hnode node, t_stack *origina, t_stack *originb, t_moves mvs);
void	ft_moveChar(char c, t_stack *a, t_stack *b, t_moves mvs);


long	ft_hashcode(int *arr, int length);
long	ft_hashcode_node(t_stack a, t_stack b);

t_Hnode	*ft_newHnode(t_stack a, t_stack b, int step);
t_Hnode2	*ft_newHnode2(t_stack a, t_stack b, int step);
void	ft_Qpush(t_list **q, t_list *elm);
t_list	*ft_Qpop(t_list **q);
int		ft_eqlHnode(t_Hnode *a, t_Hnode *b);
t_Hnode	*ft_bfs(t_stack a, t_stack b, t_moves mvs);

#endif