#include "get_next_line.h"

void	ft_print_buffer(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	len;
	char *new_str;
	int	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strcpy(char *dest, char *str, char c)
{
	int	i;

	i = 0;
	if (!dest || !str)
		return ;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == c && c != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

/* char	*ft_realloc_buff(char *last_buff, char *str, int z)
{
	char	*temp_buff;
	int	size;

	temp_buff = ft_strdup(last_buff);
	size = BUFFER_SIZE * z;
	free (last_buff);
	last_buff = malloc (sizeof(char) * (size + 1));
	if (!last_buff)
		return (NULL);
	ft_strcpy(last_buff, temp_buff, '\0');
	if (*str)
		ft_strcpy(&(last_buff[size - BUFFER_SIZE]), str, '\0');
	last_buff[size] = '\0';
	free(temp_buff);
	return (last_buff);
} */


char	*ft_realloc_buff(char *last_buff, char *str, int z)
{
	char	*temp_buff;
	char	*new_buff;
	int	size;

	if (!str)
		return (last_buff);
	temp_buff = ft_strdup(last_buff);
	size = BUFFER_SIZE * z;
	new_buff = malloc (sizeof(char) * (size + 1));
	if (!new_buff)
		return (NULL);
	ft_strcpy(new_buff, temp_buff, '\0');
	ft_strcpy(&(new_buff[size - BUFFER_SIZE]), str, '\0');
	new_buff[size] = '\0';
	free(temp_buff);
	free(last_buff);
	return (new_buff);
}
