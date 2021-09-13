#first parts 
SRC :=	main.c src/ft_stack.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		src/ft_stack2.c src/ft_moves.c src/ft_moves2.c src/ft_moves3.c src/ft_stack3.c \
		src/ft_init.c  src/ft_print.c src/ft_hash.c src/ft_queue.c src/ft_bfs.c src/ft_string.c

#bonnus 
BSRC :=	$(SRC)

CC = gcc

FLGS = -Wall -Werror -Wextra
FBSIZE =	-D BUFFER_SIZE=42

HEADER = push_swap.h
LIBFT = libft/libft.a

NAME = push_swap


all :$(NAME)
	
$(NAME): $(SRC) $(HEADER) $(LIBFT)
	@echo "compiling ..."
	@$(CC) $(FLGS) $(FBSIZE) $(SRC) $(LIBFT) -o $(NAME)

bonus: $(BSRC) $(HEADER) $(LIBFT)
	@echo "compiling bonus ..."
	@rm -f $(NAME)
	@$(CC) $(FLGS) $(FBSIZE) $(BSRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C libft/
	@make bonus -C libft/

so:
	@echo "clreating .so file ..."
	@$(CC) -fPIC $(CFLAGS) -c $(SRC)
	@gcc -shared -o $(NAMESO) $(OBJ)


clean:
	@echo "cleaning all objects"
	@make clean -C libft/

fclean: clean
	@echo "cleaning every thing ..."
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

test:
	@make -C libft/
	@$(CC) $(FBSIZE) $(BSRC) libft/libft.a  -o tst

debug: $(SRC) $(HEADER) $(LIBFT)
	@make debug -C libft/
	@echo "compiling with -g ..."
	@$(CC) -g $(FBSIZE) $(SRC) $(LIBFT) -o tst

.PHONY: all clean fclean bonus so re test

#&.c : &.o libft.a 