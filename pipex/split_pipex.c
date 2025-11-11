/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:56:43 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/11 11:39:26 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_valid_limiters(char *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str == delimiter && i <= 2)
		{
			count++;
			i++;
		}
		str++;
	}
	return (count);
}

int	delimiters(char **strs, char **str, char limiter, int	*i)
{
	char	*start;
	int		size;

	if (find_valid_limiters((*str), limiter) == 2)
	{
		(*str)++;
		size = size_str(*str, limiter);
		if (size != 0)
			strs[*i] = new_str(*str, size);
		if (*((*str) + 1) != '\0')
			(*str)++;
	}
	else
	{
		size = size_str(*str, ' ');
		strs[*i] = new_str(*str, size);
	}
	return (size);
}

void	add_strs(char **strs, char *str, char delimiter)
{
	int		i;
	int		size;
	int		spaces;
	int		limiter;

	i = 0;
	while (*str)
	{
		jump_spaces(&str);
		limiter = *str;
		if ((limiter == '\'' || limiter == '\"') && *(str - 1) != '\\')
			size = delimiters(strs, &str, limiter, &i);
		else
		{
			size = size_str(str, delimiter);
			strs[i] = new_str(str, size);
		}
		i++;
		str += size;
	}
	strs[i] = NULL;
}

char	**ft_split_pipex(char *str, char delimiter)
{
	char	**strs;
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			word++;
		i++;
	}
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	add_strs(strs, str, delimiter);
	find_chars_scapes(strs);
	return (strs);
}
