/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:56:43 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/10/07 14:44:58 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *new_str(char *str, int size)
{
	int	i;
	char *new;

	i = 0;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i] && i < size)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

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

int	find_other_limiter(char *str, char limiter)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != limiter)
		i++;
	if (str[i] == limiter)
		return (1);
	return (0);
}

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

void	add_strs(char **strs, char *str, char delimiter)
{
	int	i;
	int	size;
	int	spaces;
	int	limiter;

	i = 0;
	while (*str)
	{
		jump_spaces(&str);
		limiter = *str;
		if (limiter == '\'' || limiter == '\"')
		{
			if (find_valid_limiters((str), limiter) == 2)
			{
				str++;
				size = size_str(str, limiter);
				if (size != 0)
					strs[i] = new_str(str, size);
				if(*(str + 1) != '\0')
					str++;
			}
			else
			{
				size = size_str(str, delimiter);
				strs[i] = new_str(str, size);
			}
		}
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


/*
while (*str)
	{
		spaces = jump_spaces(str);
		str += spaces;
		limiter = *str;
		if (limiter == '\'' || limiter == '\"')
		{	
			if (find_other_limiter(str + 1, limiter) == 1)
			{
				str++;
				size = size_str(str, limiter);
			}
			else
			{
				str++;
				size = size_str(str, ' ');
			}
			strs[i] = new_str(str, size);
			i++;
			str+=size;
		}
			// flag_str(&str, strs, &i);
		else
		{
			size = size_str(str, delimiter);
			strs[i] = new_str(str, size);
			i++;
			str+=size;
		}
} 
 */

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

/* int main(void)
{
	int	i = 0;
	char **aa = ft_split_pipex("Hola que tal estas", ' ');
	while (aa[i] != NULL)
	{
		ft_printf("%s\n", aa[i]);
		i++;
	}
} */