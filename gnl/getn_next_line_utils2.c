
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