CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft
SRC= ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c

OBJ= $(SRC:.c=.o)
ARFLAGS= rcs

all: create_obj compress

create_obj:
	$(CC) -c $(SRC)

compress: $(OBJ)
	ar $(ARFLAGS) $(NAME).a $(OBJ)

clean:
	rm $(OBJ)
oa:
	rm $(NAME).a
out:
	rm *.out
fclean: clean
	rm $(NAME).a
bonus:

re: fclean all

.PHONY: all create_obj compress clean oa out fclean re