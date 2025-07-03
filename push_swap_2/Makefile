NAME =  push_swap
CC = cc
# FLAGS_CC= -Wall -Werror -Wextra
SRC = main.c \
	moves.c \
	utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -o $(NAME) libft/libft.a libft/ft_printf/libftprintf.a
%.o : %.c
	$(CC) $(FLAGS_CC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re