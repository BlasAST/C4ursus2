/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algoritm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:10:33 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/11 14:18:33 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_swap_node *node, int max)
{
	int	pos;

	pos = 0;
	while (node != NULL)
	{
		if (node->index == max)
			return (pos);
		node = node->next;
		pos++;
	}
	return (pos);
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 7);
	else
		return (size / 11);
}

int	get_max_index(t_swap_node *node)
{
	int	max;

	max = node->index;
	while (node != NULL)
	{
		if (max < node->index)
			max = node->index;
		node = node->next;
	}
	return (max);
}
