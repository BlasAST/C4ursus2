/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:42:35 by blas              #+#    #+#             */
/*   Updated: 2025/11/19 01:25:24 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// * Funcines temporales que luego se pueden borrar
void	print_content(void *content)
{
	ft_printf("%s", (char *)content);
}

void	print_matrix(t_data *dt)
{
	int	x;
	int	y;

	y = 0;
	if (!dt->map)
		return ;
	ft_printf("MATRIZ COMPLETA (Z y Color):\n\n");
	while (y < dt->map_size_h)
	{
		x = 0;
		while (x < dt->map_size_w)
		{
			ft_printf("%d(0x%x) ", dt->map[y][x].z, dt->map[y][x].color);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}