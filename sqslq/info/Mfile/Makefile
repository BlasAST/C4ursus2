CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
NAME =libftprintf.a
SRC_PF = ft_params.c \
	ft_printchar.c\
	ft_printdec.c \
	ft_printeger.c \
	ft_printadd.c \
	ft_printegerung.c \
	ft_printhexdown.c \
	ft_printhexup.c
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

#Ejemplo de makefile que serviria para compilar solo lo necesario,
# hay otras formas como meter los archivos de libft/ directamente
# junto al resto de srcs. Que es más sencillo pero a mi esto me parece má bonito :)
