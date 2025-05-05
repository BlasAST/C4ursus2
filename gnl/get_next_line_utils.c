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
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_clean_last_buff(char **last, char *buffer)
{
	char	*temp;

	free (buffer);
	if (*last && **last != '\0')
	{
		temp = *last;
		*last = NULL;
		return (temp);
	}
	free(*last);
	*last = NULL;
	return (NULL);
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
	while (str[i] && str[i] != '\0')
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

char	*ft_realloc_buff(char *last_buff, char *str)
{
	char	*new_buff;
	int	len1;
	int	len2;

	if (!str)
		return (NULL);
	len1 = ft_strlen(last_buff);
	len2 = ft_strlen(str);
	new_buff = malloc (sizeof(char) * (len1 + len2 + 1));
	if (!new_buff)
		return (NULL);
	ft_strcpy(new_buff, last_buff, '\0');
	ft_strcpy(new_buff + len1, str, '\0');
	free(last_buff);
	return (new_buff);
}
