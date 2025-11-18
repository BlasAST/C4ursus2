/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:22:12 by blas              #+#    #+#             */
/*   Updated: 2025/11/18 01:26:59 by blas             ###   ########.fr       */
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


void    frees_t_data(t_data *dt, int code)
{
        ft_lstclear(&(dt->map_lines), free);
        free_map(dt->map_z_values, dt->map_size_h);
        clean_and_exit(dt, code);
}