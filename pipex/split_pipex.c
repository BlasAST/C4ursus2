/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:56:43 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/10/06 14:05:19 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *new_str(char *str, int size, char delimiter)
{
	int	i;
	char *new;

	i = 0;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i] && i < size && str[i] != delimiter)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	jump_spaces(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
	{
		i++;
		str++;
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

void	add_strs(char **strs, char *str, char delimiter)
{
	int	i;
	int	size;
	int	spaces;

	i = 0;
	size = 0;
	spaces = 0;
	while (*str)
	{
		spaces = jump_spaces(str);
		str += spaces;
		size = size_str(str, delimiter);
		strs[i] = new_str(str, size, delimiter);
		i++;
		str+=size;
	}
	strs[i] = NULL;
}

char **ft_split_pipex(char *str, char delimiter)
{
	char 	**strs;
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
	strs = (char **)malloc(word * sizeof(char *));
	if (!strs)
		return (NULL);
	add_strs(strs, str, delimiter);
	return (strs);
}

int main(void)
{
	int	i = 0;
	char **aa = ft_split_pipex("Hola que tal estas", ' ');
	while (aa[i] != NULL)
	{
		ft_printf("%s\n", aa[i]);
		i++;
	}
}