/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:27:48 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/18 18:10:38 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Fichero para el parseo de datos y manejo de distintos parseos

void	put_sizes_fdf(t_data *dt, char *file)
{
	char	**strs;
	int	points;

	ft_bzero(dt, sizeof(t_data));
	dt->file = file;
	dt->map_lines = read_file(dt->file);
	if (dt->map_lines == NULL)
	{
		frees_t_data(dt);
		error_ex("Mapa vacio:\n",1);
	}
	dt->map_size_h = ft_lstsize(dt->map_lines);
	strs = ft_split(dt->map_lines->content, ' ');
	if (!strs)
	{
		frees_t_data(dt);
		error_ex("Error asignación split", 1);
	}
	points = points_paint_split(strs);
	dt->map_size_w = points;
	free_split(strs);
	check_lines_width(dt);
}