/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:39:18 by marvin            #+#    #+#             */
/*   Updated: 2025/07/01 14:44:54 by bsiguenc         ###   ########.fr       */
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

int	ft_find_smaller(int *arr, int smaller, int size)
{
	int	i;
	int	new_smaller;

	i = 0;
	printf("Len: %d", size);
	if (size  == 0)
		return (2147483647);
	new_smaller = arr[0];
	while (i < size)
	{
		if (arr[i] > smaller && arr[i] < new_smaller)
			new_smaller = arr[i];
		i++;
	}
	return (new_smaller);
}

// int	ft_find_smaller(int *arr, int smaller)
// {
// 	int	i;
// 	int new_smaller;
// 	int	size;
// 	i = 0;
// 	size = ft_len_arr(arr);
// 	if (size == 0)
// 		return (2147483647);
// 	new_smaller = 2147483647;
// 	while (i < size)
// 	{
// 		if (arr[i] < new_smaller && arr[i] > smaller)
// 			new_smaller = arr[i];
// 		i++;
// 	}
// 	return (new_smaller);
// }


// int	ft_find_smaller(int *arr, int smaller)
// {
// 	int	i;
// 	int	j;
// 	int new_smaller;
// 	int	size;

// 	i = 0;
// 	j = 0;
// 	size = ft_len_arr(arr);
// 	if (size == 0)
// 		return (0);	
// 	new_smaller = arr[0];
// 	while (arr[i])
// 	{
// 		if (new_smaller > arr[i] && new_smaller > smaller && arr[i] != smaller)
// 			new_smaller = arr[i];
// 		i++;
// 	}
// 	return (new_smaller);
// }

/*
CODE 2:
int	ft_find_smaller(int *arr)
{
	int	i;
	int	j;
	int smaller;

	i = 0;
	j = 0;
	smaller = arr[0];
	while (arr[i])
	{
		if (smaller > arr[i])
		{
			smaller = arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}	
*/