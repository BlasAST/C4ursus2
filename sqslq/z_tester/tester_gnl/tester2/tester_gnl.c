#include "get_next_line.h"

void	ft_print_buffer(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	scape_buffer(int fd)
{
	int bytes;
	char *c;

	c = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!c)
		return ;
	bytes = read(fd, c, BUFFER_SIZE);
	if (bytes <= 0)
		return ;
}

void	file_null(int fd)
{
	int bytes;
	char *c;

	c = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	if (!c)
		return ;
	while (bytes > 0)
	{
		bytes = read(fd, c, BUFFER_SIZE);
		if (bytes <= 0)
			return ;
		c[bytes] = '\0';
	}
}

int main(void)
{
	// int value = open("tester2/el_quijote.txt", O_RDONLY);
	int value = open("tester2/nose.txt", O_RDONLY);
	// int value = open("tester2/empty.txt", O_RDONLY);
	// int value = open("tester2/archivo.bin", O_RDONLY);
	char *c;
	while ((c = get_next_line(0)))
	{
		ft_print_buffer(c);
		free(c);
	}
	
	/* ft_print_buffer(get_next_line(value));
	write(1, "\n", 1);
	scape_buffer(value);
	ft_print_buffer(get_next_line(value));
	write(1, "\n", 1);
	scape_buffer(value);
	ft_print_buffer(get_next_line(value));
	write(1, "\n", 1);
	scape_buffer(value);
	ft_print_buffer(get_next_line(value));
	write(1, "\n", 1);
	scape_buffer(value);
	ft_print_buffer(get_next_line(value));
	file_null(value);
	scape_buffer(value);
	ft_print_buffer(get_next_line(value)); */
}