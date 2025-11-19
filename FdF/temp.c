/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:42:35 by blas              #+#    #+#             */
/*   Updated: 2025/11/19 12:53:10 by bsiguenc         ###   ########.fr       */
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
			if (dt->map[y][x].z == 0)
				ft_printf("0  ");
			else
				ft_printf("%d ", dt->map[y][x].z);
			// (0x%x) , dt->map[y][x].color
			x++;
		}
		ft_printf("\n");
		y++;
	}
}