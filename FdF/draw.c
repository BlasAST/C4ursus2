/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/10 16:25:25 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw(char *file, t_list **node)
{
	*node = read_file(file);
	if (*node == NULL)
		error_ex("Error al almacenar lineas");
}

// Función extra anterior
void	paint(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_size_h)
	{
		x = 0;
		while (x < data->map_size_w)
		{
			// if (y >= 500 && (x >50 && x < 200))
			// 	put_pixel(&(data->i_d), x, y, color);
			// if (y >= 500 && (x > 300 && x < 450))
			// 	put_pixel(&(data->i_d), x, y, color);
			// if (y < 500 && (x > 200 && x < 300))
			// 	put_pixel(&(data->i_d), x, y, color);
			// x++;
		}
		y++;
	}
}
/* Funcion de prueba */
/* void    clear_image(t_data *data, int color)
{
    int x;
    int y;

    y = 0;
    // ➡️ Itera sobre el ALTO de la ventana
    while (y < data->map_size_h)
    {
        x = 0;
        // ➡️ Itera sobre el ANCHO de la ventana
        while (x < data->map_size_w)
        {
            // Llama a tu función para pintar el píxel en (x, y)
            put_pixel(&(data->i_d), x, y, color);
            x++;
        }
        y++;
    }
} */