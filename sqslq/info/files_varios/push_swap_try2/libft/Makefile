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
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_itoa.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRC_BONUS= ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

SRC_PRINTF= ft_printf/ft_printf.c \
	ft_printf/src/ft_utils.c\
	ft_printf/src/ft_utils2.c

OBJ= $(SRC:.c=.o)
OBJ_BONUS= $(SRC_BONUS:.c=.o)
OBJ_PRINTF= $(SRC_PRINTF:.c=.o)
ARFLAGS= rcs

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/%.c : ft_printf/%.o
	make -C ft_printf all
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_PRINTF)
	make -C ft_printf all
	ar $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_PRINTF)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

fclean_bonus: clean_bonus
	rm -f $(NAME)

bonus: $(OBJ_BONUS) $(OBJ)
	ar $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

re: fclean all

.PHONY: all clean bonus fclean re