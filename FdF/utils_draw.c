/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:50:36 by blas              #+#    #+#             */
/*   Updated: 2025/11/20 01:55:46 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *dt, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= dt->map_size_w_view || y < 0 || y >= dt->map_size_h_view)
		return ;
	dst = dt->i_d.addr + (y * dt->i_d.line_length + x * \
(dt->i_d.bit_per_pixel / 8));
	*(unsigned int *) dst = color;
}

// int	ft_round(double num)
// {
// 	if (num < 0)
// 		return ((int)(num - 0.5));
// 	return ((int)(num + 0.5));
// }

void	draw_line(t_data *dt, t_point p1, t_point p2)
{
	double	dx;
	double	dy;
	int		steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / (double) steps;
	y_inc = dy / (double) steps;
	x = p1.x;
	y = p1.y;
	while (steps >= 0)
	{
		put_pixel(dt, (int)round(x), (int)round(y), p1.color);
		x += x_inc;
		y += y_inc;
		steps--;
	}
}

void	max_size_z(t_data *dt)
{
	int	x;
	int	y;
	int	max;

	max = 0;
	y = 0;
	while (y < dt->map_size_h)
	{
		x = 0;
		while (x < dt->map_size_w)
		{
			if (abs(dt->map[y][x].z) > max)
				max = abs(dt->map[y][x].z);
			x++;
		}
		y++;
	}
	dt->max_z = max;
}
