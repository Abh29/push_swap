#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				index_flag;
	int				seq_count;
	int				to_stack_B;
	int				to_stack_A;
	int				num_in_A;
	int				rrb_to_B0;
	int				rb_to_B0;
	int				rrr_to_A0_B0;
	int				ra_to_A0;
	int				rra_to_A0;
	int				rr_to_A0_B0;
	int				dir;
	int				place_in_A;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	char	*seq;
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*magic_num_ptr;
	int		error;
	int		max;
	int		initial_stack_size;
	t_list	*ptr;
	int		place;
	int		working_index;
	int		magic_num;
}			t_stack;

void	find_num_A_for_each_B(t_stack *s);
void	count_RB_RRB(t_stack *s);
void	count_RA_RRA(t_stack *s);
void	count_RR_RRR(t_stack *s);
void	error_close(t_stack *s);
void	seq_validation(t_stack *s, int ac, char **av);
void	place_zero_as_first_elem(t_stack *s);
void	stack_B_loop_params_reset(t_stack *s);
void	push_swap_close(t_stack *s);
int		find_max_in_stack(t_list *ptr);
int		find_min_in_stack(t_list *ptr);
void	move_num_to_stackA_move(t_stack *s);
void	move_num_to_stackA_counting(t_stack *s);
void	move_num_to_stackA(t_stack *s);
int		check_curr_num(t_stack *s, int curr_num);
void	move_num_to_stackB(t_stack *s);
void	scfee_internal_loop(t_stack *s, t_list *magic_number_ptr);
void	seq_count_for_every_elem(t_stack *s);
void	find_best_magic_num(t_stack *s);
void	find_num_longest_seq(t_stack *s);
void	elem_init(t_list *elem);
void	stack_init(t_stack *s);
void	find_num_longest_seq(t_stack *s);
void	sort_main(t_stack *s);
void	move_element_to_first(t_stack *s);
void	sort_3(t_stack *s);
void	sort_5(t_stack *s);
void	find_max_in_stack_A(t_stack *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	sort_B0(t_stack *s, int index, int place, int count);
void	move_count_solving(t_stack *s, int index);
void	sorting(t_stack *stacks);

int		ft_lstsize(t_list *lst);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
long	ft_atoi(const char *str, t_stack *s);
t_list	*ft_lstnew(int num, t_stack *s);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lst_before_last(t_list *lst);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	ft_lstclear(t_list **lst);

void	pa(t_stack *s);
void	pb(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
#endif
