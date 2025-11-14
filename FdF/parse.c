/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:27:48 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/14 17:14:45 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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