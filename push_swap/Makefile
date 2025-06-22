CC = cc
FLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
NAME = push_swap.a
SRC_PS = main.c \
	utils.c

OBJ_PS = $(SRC_PS:.c=.o)

all: $(NAME)

$(NAME) :$(OBJ_PS)
	ar $(ARFLAGS) $(NAME) $(OBJ_PS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_PS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re