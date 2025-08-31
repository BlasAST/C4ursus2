NAME=pipex
CC=cc
C_FLAGS= -Wall -Werror -Wextra

SRC= src/main.c \
	src/files.c \
	src/forks.c \
	src/exec.c

OBJ_SRC = $(SRC:.c=.o)

$(NAME): $(OBJ_SRC)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	make -C libft 
	$(CC) $(OBJ_SRC) -o $(NAME) libft/libft.a libft/ft_printf/libftprintf.a
%.o : %.c
	$(CC) $(FLAGS_CC) -c $< -o $@

clean:
	rm -f $(OBJ_SRC)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all

.PHONY: all clean fclean re