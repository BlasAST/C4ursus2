/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:26 by marvin            #+#    #+#             */
/*   Updated: 2025/11/01 19:16:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
	t_data	*df;

	df = (t_data *)malloc(sizeof(t_data));
	if (!df)
		return (1);
	ft_bzero(df, sizeof(t_data));
	df->mlx_ptr = mlx_init();
	df->win_ptr = mlx_new_window(df->mlx_ptr,900,500,"Salu2");
	df->i_d.img = mlx_new_image(df->mlx_ptr,900,500);
	df->i_d.addr = mlx_get_data_addr(df->i_d.img, &df->i_d.bit_per_pixel,
	&df->i_d.line_length, &df->i_d.endian);
	// my_function_paint();
	mlx_put_image_to_window(df->mlx_ptr, df->win_ptr, df->i_d.img, 0, 0);
	mlx_loop(df->mlx_ptr);
}