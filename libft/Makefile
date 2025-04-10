CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRC=ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c

OBJ= $(SRC:.c=.o)
ARFLAGS= rcs

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJ)
	ar $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm $(OBJ)
oa:
	rm $(NAME)
fclean: clean
	rm $(NAME)
# bonus:

re: fclean all

.PHONY: all clean oa fclean re