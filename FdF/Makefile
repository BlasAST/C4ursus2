NAME    = fdf
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = main.c \
		utils_1.c \
		functions_win.c \
		events.c \
		draw.c \
		utils_file.c \
		errors.c \
		exits.c
OBJS    = $(SRCS:.c=.o)

# MLX_DIR = minilibx-linux
# MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft bonus
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a libft/ft_printf/libftprintf.a \
	-L minilibx-linux/ -lmlx -lXext -lX11
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C libft clean_bonus
	make -C minilibx-linux clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean_bonus
re: fclean all

.PHONY: all clean fclean re