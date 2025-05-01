
#include "get_next_line.h"

char    *ft_clean_buffer(char *c)
{
	free(c);
	return (NULL);
}

char	*ft_copy(char *str, char *str2)
{
	int	i;

	i = 0;
	while (*str && *str2)
	{
		str[i] = str2[i];
		i++;
	}
	
	return (str);
}

int	ft_strlen (char *str)
{
	int	size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	return (size);
}


char	*ft_find_jump(int fd, char *str, int z)
{
	int	bytes;
	int	i;
	char *str_temp;

	str_temp = ft_realloc(str_temp, z);
	bytes = read(fd, str_temp, BUFFER_SIZE);
	if (bytes == -1 || bytes == 0)
		return (ft_clean_buffer(str_temp));
	i = 0;
	while (str_temp[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (str_temp[i] != '\n')
		ft_find_jump(fd, str_temp, z++);
	else
		str_temp[i + 1] = '\0';
}

char *ft_realloc(char *str, int	z)
{
	int	i;
	int	size;
	char *new;

	i = 0;
	size = z * BUFFER_SIZE;
	new = malloc (sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new = ft_copy(new, str);
	i = ft_strlen(new);
	new[i] = '\0';
	free(str);
	return (new);
}
