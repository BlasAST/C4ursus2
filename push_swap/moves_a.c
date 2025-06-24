/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:16:19 by marvin            #+#    #+#             */
/*   Updated: 2025/06/24 17:12:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *arr)
{
	int	temp;

	if (ft_len_arr(arr) <= 0)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	ft_printf("sa\n");
}

void	push_a(int *arr_a, int *arr_b, int len)
{
	int	size_a;
	int	size_b;
	int	j;

	if (ft_len_arr(arr_b) == 0)
		return ;
	size_a = ft_len_arr(arr_a);
	while (size_a > 0)
	{
		if (size_a + 1 <= len)
			arr_a[size_a] = arr_a[size_a - 1];
		size_a--;
	}
	j = 0;
	arr_a[size_a] = arr_b[j];
	size_b = ft_len_arr(arr_b);
	while (j < len)
	{
		if (arr_b[j + 1])
			arr_b[j] = arr_b[j + 1];
		else
			arr_b[j] = 0;
		j++;
	}
	ft_printf("pa\n");
}

void	rotate_a(int *arr_a, int len)
{
	int	i;
	int	size;
	int	temp;

	i = 1;
	size = ft_len_arr(arr_a);
	temp = *arr_a;
	while (i < size)
	{
		if (size <= len)
			arr_a[i - 1] = arr_a[i];
		i++;
	}
	arr_a[i] = temp;
	ft_printf("ra\n");
}
