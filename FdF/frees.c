/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:22:12 by blas              #+#    #+#             */
/*   Updated: 2025/11/19 00:35:52 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    free_split(char **arr)
{
        int     i;

        i = 0;
        while (arr[i] != NULL)
        {
                free(arr[i]);
                i++;
        }
        free(arr);
}


void    frees_t_data(t_data *dt)
{
	if (dt->map_lines)
        ft_lstclear(&(dt->map_lines), free);
	if (dt->map)
        free_map(dt->map, dt->map_size_h);
	free(dt);
}

void	free_partial_map_and_exit(t_data *dt, int y)
{
	while (y >= 0)
	{
		free(dt->map[y]);
		y--;
	}
	free(dt->map);
	dt->map = NULL;
	clean_and_exit(dt, 1, 1, "Error: Memoria insuficiente para el mapa\n");
}