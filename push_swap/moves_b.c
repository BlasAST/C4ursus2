/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:57:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/25 14:07:05 by bsiguenc         ###   ########.fr       */
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
	ft_printf("sb\n");
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
		if (arr_a[j + 1] && j + 1 < len)
			arr_a[j] = arr_a[j + 1];
		else
			arr_a[j] = 0;
		j++;
	}
	ft_printf("pb\n");
}

void	rotate_b(int *arr_b, int len)
{
	int	i;
	int	size;
	int	temp;

	i = 1;
	size = ft_len_arr(arr_b);
	temp = *arr_b;
	while (i < size)
	{
		arr_b[i - 1] = arr_b[i];
		i++;
	}
	arr_b[i - 1] = temp;
	ft_printf("rb\n");
}

void	reverse_rotate_b(int *arr_b, int len)
{
	int	i;
	int	size;
	int	temp;
	int temp2;

	i = 1;
	size = ft_len_arr(arr_b);
	temp = arr_b[0];
	arr_b[0] = arr_b[size - 1];
	arr_b[size - 1] = 0;
	while (i < size)
	{
		temp2 = arr_b[i];
		arr_b[i] = temp;
		temp = temp2;
		i++;
	}
	ft_printf("rrb\n");
}