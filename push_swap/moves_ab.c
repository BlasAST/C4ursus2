/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:58:31 by marvin            #+#    #+#             */
/*   Updated: 2025/06/23 22:05:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(int *arr_a, int *arr_b)
{
	int	temp_a;
    int temp_b;

	if (ft_len_arr(arr_a) <= 0 || ft_len_arr(arr_b) <= 0)
		return ;
	temp_a = arr_a[0];
	arr_a[0] = arr_a[1];
	arr_a[1] = temp_a;
    temp_b = arr_b[0];
	arr_b[0] = arr_b[1];
	arr_b[1] = temp_b;
}
