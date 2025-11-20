/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:10:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/20 13:52:49 by bsiguenc         ###   ########.fr       */
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
		return (-1);
	}
	return (fd);
}

t_list	*read_file(char *str)
{
	int		fd;
	char	*line;
	t_list	*node;
	t_list	*temp;

	fd = open_file(str);
	if (fd < 0)
		return (NULL);
	node = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_lstnew(line);
		if (temp == NULL)
		{
			free(line);
			ft_lstclear(&node, free);
			close(fd);
			return (NULL);
		}
		ft_lstadd_back(&node, temp);
	}
	close(fd);
	return (node);
}
