/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:11:09 by blas              #+#    #+#             */
/*   Updated: 2025/11/18 18:37:37 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_matrix(t_data *dt)
{
	t_list	*temp;
	int	i;

	dt->map_z_values =(int **)malloc(sizeof(int *) * dt->map_size_h);
	if (!dt->map_z_values)
		clean_and_exit(dt, 1, 1, "Error asignación de memoria");
	temp = dt->map_lines;
	i = 0;
	while (temp != NULL)
	{
		dt->map_z_values[i] = (int *)malloc(sizeof(int) * dt->map_size_w);
		temp = temp->next;
		i++;
	}
}