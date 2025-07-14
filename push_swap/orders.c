/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:10:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/12 00:49:49 by aisber           ###   ########.fr       */
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

int	ft_find_nex_min(swap_node **node, int min)
{
	int	new_min;
	swap_node *temp;

	if (!node || !*node)
		return (0);
	temp = *node;
	if (ft_nodes_in_order(node) == 0)
		return (min);
	new_min = temp->value;
	while (temp != NULL)
	{
		if (temp->value > min && temp->value < new_min)
			new_min = temp->value;
		temp = temp->next;
	}
	return (new_min);
}


void	conditions_min_a(swap_node **a, swap_node **b, int min_a, int min_b)
{
	while ((*a)->value != min_a && check_in_nodes(*a, min_a) == 0)
	{
		push(a, b, "pb");
	}
		rotate(a,"ra");
}

void	conditions_min_b(swap_node **a, swap_node **b, int min_a, int min_b)
{
	if (!b || !*b)
		return ;
	while ((*b)->value != min_b && check_in_nodes(*b, min_b) == 0)
	{
		rotate(b,"rb");
	}
	push(b,a,"pa");
}