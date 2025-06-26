/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:39:18 by marvin            #+#    #+#             */
/*   Updated: 2025/06/26 16:01:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_filter_swap(int	*a)
{
	int	i;
	int	temp;

	i = 1;
	temp = a[0];
	while (i < ft_len_arr(a))
	{
		if (temp > a[i])
			return (1);
		temp = a[i];
		i++;
	}
	return (0);
}