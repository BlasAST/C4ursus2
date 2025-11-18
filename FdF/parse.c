/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:27:48 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/18 01:52:38 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Fichero para el parseo de datos y manejo de distintos parseos

void	put_sizes_fdf(t_data *dt)
{
	char	**strs;
	int	points;

	dt->map_lines = read_file(dt->file);
	// ! Preguntar si esto es necesario:
	if (dt->map_lines == NULL)
		error_ex("Mapa vacio:\n",1);
	dt->map_size_h = ft_lstsize(dt->map_lines);
	strs = ft_split(dt->map_lines->content, ' ');
	// ! Esto tmb
	if (!strs)
	{
		ft_lstclear(&(dt->map_lines), free);
		error_ex("Error asignación split", 1);
	}
	points = points_paint_split(strs);
	dt->map_size_w = points;
	check_lines_width(dt);
	free_split(strs);
	// ft_lstiter(dt->map_lines, print_content);
}