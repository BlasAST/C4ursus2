/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:57:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/23 23:37:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(int *arr)
{
	int	temp;

	if (ft_len_arr(arr) <= 0)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void	push_b(int *arr_b, int *arr_a, int len)
{
	int	size_b;
	int	size_a;
	int	j;

	if (ft_len_arr(arr_a) == 0)
		return ;
	size_b = ft_len_arr(arr_b);
	while (size_b > 0)
	{
		if (size_b + 1 <= len)
			arr_b[size_b] = arr_b[size_b - 1];
		size_b--;
	}
	j = 0;
	arr_b[size_b] = arr_a[j];
	size_a = ft_len_arr(arr_a);
	while (j < len)
	{
		if (arr_a[j + 1])
			arr_a[j] = arr_a[j + 1];
		else
			arr_a[j] = 0;
		j++;
	}
}