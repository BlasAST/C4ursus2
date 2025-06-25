/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:58:31 by marvin            #+#    #+#             */
/*   Updated: 2025/06/25 14:11:01 by bsiguenc         ###   ########.fr       */
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

void	rotate_ab(int *arr_a, int *arr_b)
{
	int	i;
	int	size_a;
	int	size_b;
	int	temp;

	i = 1;
	size_a = ft_len_arr(arr_a);
	temp = *arr_a;
	while (i < size_a)
	{
		arr_a[i - 1] = arr_a[i];
		i++;
	}
	arr_a[i - 1] = temp;
	i = 0;
	size_b = ft_len_arr(arr_b);
	temp = *arr_b;
	while (i < size_b)
	{
		arr_b[i - 1] = arr_b[i];
		i++;
	}
	arr_b[i - 1] = temp;
	ft_printf("rr\n");
}
