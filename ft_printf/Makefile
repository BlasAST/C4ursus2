CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
NAME =libftprintf.a
SRC_PF = ft_printf.c \
	ft_printchar.c\
	ft_printdec.c \
	ft_printeger.c \
	ft_printadd.c \
	ft_printegerung.c \
	ft_printhexdown.c \
	ft_printhexup.c \
	ft_printstr.c
OBJ_PF = $(SRC_PF:.c=.o)
SRC_LIB =	libft/ft_strlen.c
OBJ_LIB = $(SRC_LIB:libft/%.c=libft/%.o)

all: $(NAME)

$(NAME): $(OBJ_PF) $(OBJ_LIB)
	ar $(ARFLAGS) $(NAME) $(OBJ_PF) $(OBJ_LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ_PF) $(OBJ_LIB)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:  fclean all