/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/04 13:13:46 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	put_pixel(t_img_data *data, int x, int y, int color)
{
	char *dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	draw(char *file)
{
	// char ***lines;
	// char *line;

	read_file(file);
	
}
// Función extra anterior
void    paint(t_data *data, int color)
{
    int x;
    int y;

    y = 0;
    while (y < data->map_size_h)
    {
        x = 0;
        while (x < data->map_size_w)
        {
            put_pixel(&(data->i_d), x, y, color);
            x++;
        }
        y++;
    }
}