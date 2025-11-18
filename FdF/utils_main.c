/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:14:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/18 14:42:23 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//! Maneja funciones del main, debería de tener otro nombre

void	create_ini(t_data *df)
{
	df->map_size_h = 800;
	df->map_size_w = 600;
	df->mlx_ptr = mlx_init();
	if (!df->mlx_ptr)
	{
		free(df);
		error_ex("Error de interfaz grafica\n", 1);
	}
	df->win_ptr = mlx_new_window(df->mlx_ptr, df->map_size_w,
			df->map_size_h, "Salu2");
	df->i_d.img = mlx_new_image(df->mlx_ptr, df->map_size_w, df->map_size_h);
	df->i_d.addr = mlx_get_data_addr(df->i_d.img, &df->i_d.bit_per_pixel,
			&df->i_d.line_length, &df->i_d.endian);
}

void	finish_fdf(t_data *df)
{
	mlx_put_image_to_window(df->mlx_ptr, df->win_ptr, df->i_d.img, 0, 0);
	mlx_loop(df->mlx_ptr);
}
