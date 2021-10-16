NAME=push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -I./

SRC = 	src/main.c \
		utils/push_swap_utils1.c \
		utils/push_swap_utils2.c \
		utils/push_swap_utils3.c \
		utils/push_swap_utils4.c \
		utils/push_swap_utils5.c \
		utils/push_swap_utils6.c \
		src/push_swap_operations.c \
		src/push_swap_operations_a.c \
		src/push_swap_operations_b.c \
		src/push_swap_operations_init.c \
		src/push_swap_sorting.c \
		src/push_swap_sorting_1_to_5.c \
		src/push_swap_find_magic_num.c \
		src/push_swap_move_to_B.c \
		src/push_swap_close.c \
		src/push_swap_validation.c \
		src/push_swap_move_to_A.c \
		src/push_swap_count_min_moves.c \
		src/push_swap_sorting_find_A_for_B.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) push_swap.h
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)

%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
