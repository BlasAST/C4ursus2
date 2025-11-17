/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:10:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/17 00:48:57 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// *Funciones relacionadas con los ficheros

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error:");
		error_ex("Error en la apertura del fichero\n", 1);
	}
	return (fd);
}

t_list	*read_file(char *str)
{
	int		fd;
	char	*line;
	t_list *node;
	t_list *temp;

	fd = open_file(str);
	if (fd < 0)
		error_ex("Error en la apertura del archivo", 1);
	node = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_lstnew(line);
		ft_lstadd_back(&node, temp);
	}
	close(fd);
	return (node);
}
