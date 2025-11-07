/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:10:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/06 00:41:24 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_ex("Error en la apertura del fichero");
	return (fd);
}

int	points_paint(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n'
			&& (i == 0 || str[i - 1] == ' '))
			size++;
		i++;
	}
	return (size);
}

void	print_content(void *content)
{
	ft_printf("%s", (char *)content);
}

t_list	*read_file(char *str)
{
	int		fd;
	char	*line;
	t_list *node;
	t_list *temp;

	fd = open_file(str);
	if (fd < 0)
		return (NULL);
	node = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_lstnew(line);
		ft_lstadd_back(&node, temp);
	}
	return (node);
}
