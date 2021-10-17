/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:11:37 by mehill            #+#    #+#             */
/*   Updated: 2021/10/17 00:18:51 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

# define MAX_SIZE 1000

typedef struct s_stack
{
	int	arr[MAX_SIZE];
	int	head;
	int	tail;
	int	size;
}				t_stack;

typedef char	t_move(t_stack *a, t_stack *b);

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

typedef struct s_solve
{
	t_stack	*a;
	t_stack	*b;
	int		idxA[MAX_SIZE];
	int		idxB[MAX_SIZE];
	int		sizeA;
	int		sizeB;
}				t_solve;

typedef struct s_param
{
	t_stack		*a;
	t_stack		*b;
	t_moves		*mvs;
	t_string	*str;
}				t_param;

# define ACC 1
# define DEC 2

/**** stack ******/
t_stack		ft_newstack(void);
void		ft_push(t_stack *s, int elm);
int			ft_pop(t_stack *s);
int			ft_isempty(t_stack *s);
int			ft_find(t_stack *s, int elm);
int			ft_issorted(t_stack *s, int ord);
int			ft_isfull(t_stack *s);
void		ft_pushbottom(t_stack *s, int elm);
int			ft_popbottom(t_stack *s);
void		ft_quicksort(int *arr, int first, int last);
void		ft_stkdup(t_stack stk, t_stack *dup);
void		ft_sorted_arr(t_stack stk, int *arr);
int			ft_getindex(t_stack a, int index);
int			ft_equstack(t_stack a, t_stack b);
int			ft_binarySearch(int *arr, int left, int right, int key);
void		ft_stk_to_arr(t_stack stk, int *arr);
int			ft_indexOf(int *arr, int size, int key);
void		ft_swap(int *arr, int i, int j);

/*****************/

/***** moves *****/
char		ft_sa(t_stack *a, t_stack *b);
char		ft_sb(t_stack *a, t_stack *b);
char		ft_ss(t_stack *a, t_stack *b);
char		ft_ra(t_stack *a, t_stack *b);
char		ft_rb(t_stack *a, t_stack *b);
char		ft_rr(t_stack *a, t_stack *b);
char		ft_rra(t_stack *a, t_stack *b);
char		ft_rrb(t_stack *a, t_stack *b);
char		ft_rrr(t_stack *a, t_stack *b);
char		ft_pa(t_stack *a, t_stack *b);
char		ft_pb(t_stack *a, t_stack *b);

/****************/

void		ft_init(t_moves *mvs);
void		ft_exit(char *msg, int err);
int			ft_is_simp_number(char *str);
void		ft_read_args(int argc, char **argv, t_stack *a);

char		ft_charAt(t_string s, int index);
int			ft_catstr(t_string *s, char *str);
int			ft_catchar(t_string *s, char c);
t_string	*ft_newString(int max_l);
void		ft_freeString(t_string **str);

void		ft_printstack(t_stack *a);
void		ft_printboth(t_stack *a, t_stack *b);
void		ft_printarr(int *arr, int size, int fd);

void		ft_stepi(t_solve *info, t_move *mv, int i, t_string *str);

void		ft_solve_xs(t_param *param);
void		ft_solve_s(t_param *param);
void		ft_solve_xm(t_param *param);
void		ft_solve_m(t_param *param);
void		ft_solve_l(t_param *param);
void		ft_solve(t_param *param);

//testing a new solution 
int			ft_find_head(t_stack a);
int			ft_lis_length(int arr[], int n);
void		ft_stk_arr_head(t_stack stk, int *arr, int head);
void		ft_find_lis(int arr[], int lis[], int n, int *length);
void		ft_push_to_a(t_param *param);
void		ft_push_to_b(t_param *param);
int			ft_get_moves(t_param *param, int elm);
int			ft_get_best(t_param *param);
int			ft_step_top(t_stack *a, int elm);
int			ft_step_proper(t_stack *a, int elm);
int			ft_step_top(t_stack *a, int elm);
int			ft_min_stk(t_stack a);
int			ft_max_stk(t_stack a);
void		ft_move_rep(t_move *mv, t_param *param, int rep);
void		ft_replace_args(t_stack *stk);
int			ft_abs(int a);

#endif