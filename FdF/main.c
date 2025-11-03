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

void my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
char *dst;

dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
*(unsigned int*)dst = color;
}

int create_trgb(int t, int r, int g, int b)
{
return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
return (trgb & 0xFF);
}

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
            my_mlx_pixel_put(&(data->i_d), x, y, color);
            x++;
        }
        y++;
    }
}

int main(void)
{
	t_data	*df;

	df = (t_data *)malloc(sizeof(t_data));
	if (!df)
		return (1);
	create_ini(df);
	paint(df,0x00FFFF);
	finish_fdf(df);
}