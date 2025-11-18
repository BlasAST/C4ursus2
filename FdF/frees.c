/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:22:12 by blas              #+#    #+#             */
/*   Updated: 2025/11/18 13:57:09 by bsiguenc         ###   ########.fr       */
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
	if (dt->map_z_values)
        free_map(dt->map_z_values, dt->map_size_h);
	free(dt);
}