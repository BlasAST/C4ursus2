NAME    = fdf
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = main.c \
		utils_1.c
OBJS    = $(SRCS:.c=.o)

# MLX_DIR = minilibx-linux
# MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a libft/ft_printf/libftprintf.a \
	-L minilibx-linux/ -lmlx -lXext -lX11
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all

.PHONY: all clean fclean re