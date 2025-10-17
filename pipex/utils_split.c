/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:21:35 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 11:04:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	jump_spaces(char **str)
{
	int	i;

	i = 0;
	while (**str == ' ' && **str != '\0')
	{
		i++;
		(*str)++;
	}
	return (i);
}

int	size_str(char *str, char delimiter)
{
	int	i;

	i = 0;
	while (str[i] != delimiter && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	size_scapes(char *str)
{
	int	scapes;
	int	i;

	scapes = 0;
	i = 0;
	while (str[i++])
	{
		if (str[i] == '\\' && (str[i + 1] == '\'' || str[i + 1] == '\"'))
			scapes++;
	}
	return (scapes);
}

char	*rm_scapes(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*new_str;

	size = ft_strlen(str) - size_scapes(str);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\\' && (str[i + 1] == '\'' || str[i + 1] == '\"'))
			i++;
		new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

void	find_chars_scapes(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i] != NULL)
	{
		j = 0;
		while (strs[i][j])
		{
			if (size_scapes(strs[i]) > 0)
				strs[i] = rm_scapes(strs[i]);
			j++;
		}
		i++;
	}
}
