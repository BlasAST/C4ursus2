/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:10:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/09 17:07:07 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(swap_node **node)
{
	int	min;
	swap_node *temp;

	if (!node || !*node)
		return (-2147483648);
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
	new_min = 2147483647;
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
	while ((*a)->value != min_a)
	{
		push(a, b, "pb");
	}
		rotate(a,"ra");
}

void	conditions_min_b(swap_node **a, swap_node **b, int min_a, int min_b)
{
	
}