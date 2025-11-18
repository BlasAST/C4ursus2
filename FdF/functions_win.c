/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/18 18:24:34 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
		clean_and_exit(data, 0, 0, NULL);
	return (0);
}

static int	close_button(t_data *data)
{
	clean_and_exit(data, 0, 0, NULL);
	return (0);
}

void	functions_win(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_button, data);
	/* mlx_hook(data->win_ptr,9,1L << 15, render_frame, data); */
}

/* // ! FUnción de prueba */
/* int render_frame(t_data *data)
{
    clear_image(data, 0x000000); 
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i_d.img, 0, 0);
   
    return (0);
} */
