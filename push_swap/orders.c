/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:10:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/25 18:11:50 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_in_nodes(swap_node *node, int min)
{
	while (node != NULL)
	{
		if (node->value == min)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_find_min(swap_node **node)
{
	int	min;
	swap_node *temp;

	if (!node || !*node)
		return (2147483647);
	temp = *node;
	min = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min)
		{
			min = temp->value;
		}
		temp = temp->next;
	}
	return (min);
}

void	put_index(swap_node **node, int val, int in)
{
	swap_node *temp;

	temp = *node;
	while (temp != NULL)
	{
		if (temp->value == val)
		{
			temp->index = in;
			return ;
		}
		temp = temp->next;
	}
}

int	ft_find_nex_min(swap_node **node, int min)
{
	int new_min;
	int	found;
	swap_node *temp;

	if (!node || !*node)
		return (0);
	temp = *node;
	new_min = 0;
	found = 0;
	while (temp != NULL)
	{
		if (temp->value > min)
		{
			if (!found || temp->value < new_min)
			{
				new_min = temp->value;
				found = 1;
			}
		}
		temp = temp->next;
	}
	if (found)
		return (new_min);
	return (min);
}


int	size_nodes(swap_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	add_index(swap_node **node)
{
	int	i;
	int	size;
	int	next_min;

	i = 0;
	size = size_nodes(*node);
	next_min = ft_find_min(node);
	put_index(node, next_min, i);
	i++;
	while (i < size)
	{
		next_min = ft_find_nex_min(node, next_min);
		put_index(node, next_min, i);
		i++;
	}
}