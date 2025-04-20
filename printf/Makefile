CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
LIBFT = libft.a
NAME =libftprintf.a
SRC = ft_printf.c \
	ft_putchar.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar $(ARFLAGS) $(NAME) $(OBJ) libft/libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean