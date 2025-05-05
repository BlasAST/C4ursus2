#include "get_next_line.h"

void	ft_print_buffer(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int ft_find(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == c)	
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int	len;
	int	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
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

char	*ft_clean_last_buff(char **last, char *buff, int bytes)
{
	char *temp;

	free(buff);
	if (*last)
	{
		temp = ft_strdup(*last);
		free (*last);
		*last = NULL;
		return (temp);
	}
	return (NULL);
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
	if (str[i] == c && c == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
}

char	*ft_realloc(char *last_buffer, char *buffer)
{
	char	*temp;
	int	len1;
	int	len2;

	if (!buffer)
		return (NULL);
	len1 = ft_strlen(last_buffer);
	len2 = ft_strlen(buffer);
	temp = malloc (sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, last_buffer, '\0');
	ft_strcpy(temp + len1, buffer, '\0');
	free(last_buffer);
	return (temp);
}