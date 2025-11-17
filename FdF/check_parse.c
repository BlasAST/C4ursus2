/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:31:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/17 02:16:43 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_split(void *content, void *context)
{
	int		size_temp;
	t_data *dt;
	char	*line;

	dt = (t_data *)context;
	line = (char *)content;
	size_temp = points_paint(line);
	ft_printf("%d", size_temp);
	if (size_temp != dt->map_size_w)
		error_ex("Fichero mal formateado\n", 1);
}

void	check_lines_width(t_data *dt)
{
	ft_lstiter_fdf(dt->map_lines, count_split, dt);
	ft_printf("Fichero valido\n");
}