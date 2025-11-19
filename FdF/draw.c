/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/19 16:33:16 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_point(t_point p, t_data *dt)
{
	double	x_temp;
	double	y_temp;

	x_temp = p.x;
	y_temp = p.y;
	p.x = (x_temp - y_temp) * cos(dt->angle) *dt->zoom;
	p.y = (x_temp + y_temp) * sin(dt->angle) * dt->zoom - (p.z * dt->zoom) / 2.0;
	p.x += dt->offset_x;
	p.y += dt->offset_y;
	return (p);
}

// Función extra anterior
void	draw_map(t_data *dt)
{
	int	x;
	int	y;
	t_point current;
	t_point next;

	y = 0;
	while (y < dt->map_size_h)
	{
		x = 0;
		while (x < dt->map_size_w)
		{
			current = dt->map[y][x];
			current = project_point(current, dt);
			if (x < dt->map_size_w - 1)
			{
				next = dt->map[y][x + 1];
				next = project_point(next, dt);
				draw_line(dt, current, next);
			}
			if (y < dt->map_size_h - 1)
			{
				next = dt->map[y + 1][x];
				next = project_point(next, dt);
				draw_line(dt, current, next);
			}
			x++;
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
