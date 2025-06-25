/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:02:59 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/06/23 18:00:34 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*ft_putargs(int argn, char **args)
{
	int *arr;
	int	i;

	arr = (int *) malloc (sizeof(int) * argn);
	if (!arr)
		return (NULL);
	i = 1;
	while (i <= argn)
	{
		arr[i - 1] = ft_atoi(args[i]);
		i++;
	}
	return (arr);
}

void	ft_print_arr(int  *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i])
			ft_printf("%d ", arr[i]);
		else
			ft_printf("-");
		i++;
	}
	ft_printf("\n\n");
}