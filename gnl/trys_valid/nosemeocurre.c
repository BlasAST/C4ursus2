#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char    *ft_clean_buffer(char *c);
#endif

/*
	* Quiero que lea linea por linea
	* Crear un buffer que crecerá si no encuentra un \n
	* Devolver la lectura hasta encontrar un \n
	* Almacenar en static lo que quedo del ultimo buffer
	* Hacer que vaya creciendo el buffer que teniamos
	*
 */

void	ft_print_buffer(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_strcpy (char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || ! src)
		return ;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_realloc (char *last_buffer, char *str, int z)
{
	int size;
	char	*buffer_temp;

	buffer_temp = last_buffer;
	size = BUFFER_SIZE * z;
	last_buffer = malloc (sizeof(char) * size + 1);
	if (!last_buffer)
		return (NULL);
	ft_strcpy(last_buffer, buffer_temp);
	free (buffer_temp);
	last_buffer[size + 1] = '\0';
	if (*str)
		ft_strcpy(&(last_buffer[size + 1]), str);
	return (last_buffer);
}

int	ft_find_jump (char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

/* char	*get_next_line(int fd)
{
	static	char	*last_buffer;
	char	*buffer;
	int bytes;
	int	size;

	size = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	bytes = read (fd, buffer, BUFFER_SIZE);
	if (!buffer || bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!last_buffer)
		last_buffer = ft_realloc(last_buffer, buffer, size);
	ft_strcpy(last_buffer, buffer);
	while (!ft_find_jump(buffer))
	{
		last_buffer = ft_realloc(last_buffer, buffer, size + 1);
		ft_strcpy(&(last_buffer[size * BUFFER_SIZE]), buffer);
		bytes = read (fd, buffer, BUFFER_SIZE);
		size++;
	}
	free(buffer);
	return (last_buffer);
} */

char	*get_next_line(int fd)
{
	static char *last_buffer;
	char	*buffer;
	char *return_buffer;
	int	bytes;
	int size;

	size = 1;
	// Asignar espacio a buffer
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	// Leer con el buffer
	bytes = read(fd, buffer, BUFFER_SIZE);
	// Si el buffer a encontrado el final trabajar el ultimo buffer
	if (bytes <= 0)
		return (NULL);
	// Asignar espacio a last_buffer y copiar buffer
	last_buffer = ft_realloc(last_buffer, buffer, size);
	// Buscar  \N
	// Si no se encuentra repetir
	// Asignar lo anterior a la variable estatica + size
	// realizar otra lectura para repetir
	// Si la lectura encuentra el final trabajar el ultimo buffer DEVOLVERLO A RETURN BUFFER
	// Si se detiene por el bucle devolver todo lo del buffer statico hasta el  \n
	// Se desplaza la static hasta el siguiente sin el  \n
	// Que pasa con el \n si se llama en la siguiente iteración?
	// retornar return buffer
	

	

}

int main(void)
{
	int value = open("../el_quijote.txt", O_RDONLY);
	// int value = open("nose.txt", O_RDONLY);
	char *c;
	while ((c = get_next_line(value)))
	{
		ft_print_buffer(c);
	}

	// ft_print_buffer(get_next_line(value));
}
