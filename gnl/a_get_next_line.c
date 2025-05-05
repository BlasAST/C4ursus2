#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*last_buffer;
	char	*buffer;
	char *temp;
	int	pos;
	int	bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_find(last_buffer, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (bytes <= 0)
			return (ft_clean_last_buff(&last_buffer, buffer));
		last_buffer = ft_realloc_buff(last_buffer, buffer);
	}
	free(buffer);
	if (!last_buffer || *last_buffer == '\0')
		return (NULL);
	pos = ft_find(last_buffer, '\n');
	if (pos == -1)
		return (temp = ft_strdup(last_buffer));
	temp = malloc(sizeof(char) * (pos + 2));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, last_buffer, '\n');
	buffer = ft_strdup(last_buffer + pos + 1);
	free(last_buffer);
	last_buffer = buffer;
	return (temp);
}
