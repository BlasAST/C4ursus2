CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
LIBFT = libft.a
NAME =libftprintf.a
SRC = ft_params.c \
	ft_printchar.c\
	ft_printdec.c 
OBJ = $(SRC:.c=.o)
# include -Ilibft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar x libft/libft.a
	ar $(ARFLAGS) $(NAME) $(OBJ) *.o
	rm -f *.o

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

re:  fclean all