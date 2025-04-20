CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
ARFLAGS = rcs
MF = ./libft
SRC = ft_printf.c \
	ft_putchar.c

OBJ = $(SRC:.c=.o)
OBJ_LIB = $(libft/*:.c=.o)

all: $(NAME)

LIB_RUN:
	make -C $(MF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_LIB)
	ar $(ARFLAGS) -c $(NAME) $(OBJ) $(OBJ_LIB)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

.PHONY: all LIB_RUN