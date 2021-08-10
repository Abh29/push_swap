#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

#define MAX_SIZE 500

typedef struct s_stack
{
	int	arr[MAX_SIZE];
	int	head;
	int tail;
	int size;
}				t_stack;

typedef char *t_move(t_stack *a, t_stack *b);

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


#define ACC 1
#define DEC 2

t_stack ft_newstack();
void	ft_push(t_stack *s, int elm);
int		ft_pop(t_stack *s);
int		ft_isempty(t_stack *s);
int		ft_find(t_stack *s, int elm);
int		ft_issorted(t_stack *s, int ord);
int		ft_isfull(t_stack *s);
void	ft_pushbottom(t_stack *s, int elm);
int		ft_popbottom(t_stack *s);
char	*ft_sa(t_stack *a, t_stack *b);
char	*ft_sb(t_stack *a, t_stack *b);
char 	*ft_ss(t_stack *a, t_stack *b);
char	*ft_ra(t_stack *a, t_stack *b);
char	*ft_rb(t_stack *a, t_stack *b);
char 	*ft_rr(t_stack *a, t_stack *b);
char	*ft_rra(t_stack *a, t_stack *b);
char	*ft_rrb(t_stack *a, t_stack *b);
char	*ft_rrr(t_stack *a, t_stack *b);
char	*ft_pa(t_stack *a, t_stack *b);
char	*ft_pb(t_stack *a, t_stack *b);

#endif