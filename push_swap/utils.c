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


int	*ft_putargs(int argn, char **args)
{
	int *arr;
	int	i;

	arr = (int *) malloc (sizeof(int) * argn);
	if (!arr)
		return (NULL);
	i = 1;
	while (args[i])
	{
		// arr[i - 1] = args[i];
		i++;
	}
	return (arr);
}

void	ft_print_arr(int  *arr)
{
	int	i;

	while (arr[i])
	{
		printf("%d-", arr[i]);
		i++;
	}
}