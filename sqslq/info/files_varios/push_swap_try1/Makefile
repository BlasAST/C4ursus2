CC = cc
# FLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
NAME = push_swap
SRC_PS = main.c \
	utils.c \
	moves_a.c \
	moves_b.c \
	moves_ab.c \
	filters.c

SRC_LIB = libft/ft_printf/ft_printf.c \
		    libft/ft_printf/src/ft_utils.c \
			libft/ft_printf/src/ft_utils2.c \
            libft/ft_printf/libft/ft_strlen.c \
			libft/ft_printf/libft/ft_toupper.c \
			libft/ft_printf/libft/ft_isprint.c \
			libft/ft_printf/libft/ft_isalnum.c \
			libft/ft_printf/libft/ft_isdigit.c \
			libft/ft_printf/libft/ft_isalpha.c \
			libft/ft_atoi.c

OBJ_PS = $(SRC_PS:.c=.o)
OBJS_LIB = $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME) :$(OBJ_PS) $(OBJS_LIB)
	cc $(OBJ_PS) $(OBJS_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

libft/ft_printf/%.o : libft/ft_printf/%.c
	make -C libft/ft_printf all
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ_PS)
	make -C libft/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re