/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/17 13:14:41 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// ! Función no valida, no hace nada solo guarda el dato. Modificar
void	draw(char *file, t_list **node)
{
	*node = read_file(file);
	if (*node == NULL)
		error_ex("Error al almacenar lineas", 1);
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

// * Función adicional de pintar en la matriz
int	points_paint(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n'
			&& (i == 0 || str[i - 1] == ' '))
			size++;
		i++;
	}
	return (size);
}

int	points_paint_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
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