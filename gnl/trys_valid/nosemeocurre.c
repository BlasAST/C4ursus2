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

void	ft_strcpy (char *dest, char *src, char c)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return ;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *new_str;
	int size;
	int	i;

	size = ft_strlen(str);
	new_str = malloc(sizeof(char) * size + 1);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_realloc (char *last_buffer, char *str, int z)
{
	int	size;
	char	*buffer_temp;
	int	last_pos;

	buffer_temp = last_buffer;
	size = BUFFER_SIZE * z;
	last_buffer = malloc (sizeof(char) * size);
	if (!last_buffer)
		return (NULL);
	ft_strcpy(last_buffer, buffer_temp, '\0');
	if (*str)
		ft_strcpy(&(last_buffer[size - BUFFER_SIZE]), str, '\0');
	last_buffer[size] = '\0';
	return (last_buffer);
}

int	ft_find (char *str, char find)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == find)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char *last_buffer;
	char	*buffer;
	char *return_buffer;
	int	bytes;
	int size;
	int	pos;

	size = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_find(last_buffer, '\n') == -1)
	{
		bytes = read (fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (NULL);
		buffer[bytes] = '\0';
		// Asignar lo anterior a la variable estatica + size
		last_buffer = ft_realloc(last_buffer, buffer, size);
		size++;
	}
	pos = ft_find(last_buffer, '\n');
	free(buffer);
	buffer = ft_strdup(last_buffer + pos + 1);
	return_buffer = malloc (sizeof(char) * (pos + 2));
	ft_strcpy(return_buffer, last_buffer, '\n');
	free(last_buffer);
	last_buffer = buffer;
	return (return_buffer);
}

int main(void)
{
	int value = open("../el_quijote.txt", O_RDONLY);
	// int value = open("nose.txt", O_RDONLY);
	char *c;
	/* while ((c = get_next_line(value)))
	{
		ft_print_buffer(c);
	} */

	ft_print_buffer(get_next_line(value));
	ft_print_buffer(get_next_line(value));
}
