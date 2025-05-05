#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char	*last_buffer;
	char	*buffer;
	char	*temp;
	int	bytes;
	int	pos;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_find(last_buffer, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_clean_last_buff(&last_buffer, buffer, bytes));
		buffer[bytes] = '\0';
		last_buffer = ft_realloc(last_buffer, buffer);
	}
	free(buffer);
	pos = ft_find(last_buffer, '\n');
	temp = malloc (sizeof(char) * (pos + 2));
	if (!temp)
		return(NULL);
	ft_strcpy(temp, last_buffer, '\n');
	last_buffer = ft_strdup(last_buffer + pos + 1);
	return (temp);
}

int main(void)
{
	// int value = open("el_quijote.txt", O_RDONLY);
	int value = open("nose.txt", O_RDONLY);
	char *c;
	while ((c = get_next_line(value)))
	{
		ft_print_buffer(c);
	}

	// ft_print_buffer(get_next_line(value));
	// ft_print_buffer(get_next_line(value));
	// ft_print_buffer(get_next_line(value));
}