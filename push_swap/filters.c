/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:39:18 by marvin            #+#    #+#             */
/*   Updated: 2025/06/27 15:25:19 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_filter_swap(int	*a, int len)
{
	int	i;
	int	size;
	int	temp;

	i = 1;
	size = ft_len_arr(a);
	if (size < len)
		return (1);
	temp = a[0];
	while (i < size)
	{
		if (temp > a[i])
			return (1);
		temp = a[i];
		i++;
	}
	return (0);
}

int	ft_find_smaller(int *arr, int *smaller)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		if (*smaller > arr[i])
		{
			*smaller = arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}