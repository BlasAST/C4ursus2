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

char	*get_next_line(int fd)
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
}

int main(void)
{
	int value = open("el_quijote.txt", O_RDONLY);
	// int value = open("nose.txt", O_RDONLY);
	char *c;
	/* while ((c = get_next_line(value)))
	{
	}*/

	ft_print_buffer(get_next_line(value));
}
