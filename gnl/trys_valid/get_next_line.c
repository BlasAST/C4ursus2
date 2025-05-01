
#include "get_next_line.h"

void	ft_print_buffer(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	
}
char	*get_next_line(int fd)
{
	static char *buffer;
	int	bytes;
	int	i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_clean_buffer(buffer));
	i = 0;
	bytes = read(fd, &buffer[i],1);
	if (bytes == -1 || bytes == 0)
		return (ft_clean_buffer(buffer));
	i++;
	while (buffer[i - 1] != '\n' && i < BUFFER_SIZE)
	{
		bytes = read(fd, &buffer[i], 1);
		if (bytes == -1)
			return (ft_clean_buffer(buffer));
		i++;
	}
	buffer[i + 1] = '\0';
	return (buffer);
}

int main(void)
{
	int value = open("el_quijote.txt", O_RDONLY);
	// int value = open("nose.txt", O_RDONLY);
	char *c;
	while ((c = get_next_line(value)))
	{
		ft_print_buffer(c);
	}
}

/* 
	* Realizar lectura linea por linea
	* Debe devolver la linea que se acaba de leer
	! Si no hay nada que leer o a ocurrido un error devolver NULL
	Debe funcionar con la lectura de archivo y stdin
	*La linea devuelta deve terminal con "\n" excepto si llega al final
	*	del archivo y no termina en \n
	TODO variable estatica
	*GNL debe tener un comportamiento indeterminado si
	! si el arhivo es un archivo binario aunque se puede buscar alguna forma
	! realizar solucionar el problema

	TODO Leer lo menos posible cada vez que se llame a GNL.
	TODO si se encuentra un \n debe devolver la linea
	!No leer el archivo entero y procesar cada linea
	! NO LIBFT NO LSEEK NO VARIABLES GLOBALES
 */