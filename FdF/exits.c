/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:44:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/18 13:52:46 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clean_and_exit(t_data *data, int code)
{
	if (data->i_d.img && data->mlx_ptr)
		mlx_destroy_image(data->mlx_ptr, data->i_d.img);
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data)
		frees_t_data(data);
	exit(code);
	return (0);
}

/* FUnción liberar mapa */

void	free_map(int **map_z, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_z[i]);
		i++;
	}
	free(map_z);
}
