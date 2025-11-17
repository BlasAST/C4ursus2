/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:27:48 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/17 13:24:38 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Fichero para el parseo de datos y manejo de distintos parseos

void	put_sizes_fdf(t_data *dt)
{
	char	**strs;
	int	points;

	dt->map_lines = read_file(dt->file);
	dt->map_size_h = ft_lstsize(dt->map_lines);
	strs = ft_split(dt->map_lines->content, ' ');
	points = points_paint_split(strs);
	dt->map_size_w = points;
	check_lines_width(dt);
	ft_lstiter(dt->map_lines, print_content);
}