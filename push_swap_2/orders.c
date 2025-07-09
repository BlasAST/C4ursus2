/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:10:37 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/09 19:11:33 by bsiguenc         ###   ########.fr       */
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

int	check_bigger(swap_node *node)
{
	int	max;

	max = node->value;
	while (node != NULL)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	ft_find_min(swap_node **node)
{
	int	min;
	swap_node *temp;

	if (!node || !*node)
		return (2147483647);
		// return (-2147483648);
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
	// new_min = check_bigger(*node);
	new_min = temp->value;
	while (temp != NULL)
	{
		if (temp->value > min && temp->value < new_min)
			new_min = temp->value;
		temp = temp->next;
	}
	// if (new_min < min)
	//   	new_min = min;
	return (new_min);
}


void	conditions_min_a(swap_node **a, swap_node **b, int min_a, int min_b)
{
	// if (min_a == check_bigger(*a))
	// {
	// 	conditions_min_b(a,b,min_a,min_b);
	// 	return ;
	// }
	while ((*a)->value != min_a && check_in_nodes(*a, min_a) == 0)
	{
		push(a, b, "pb");
	}
		rotate(a,"\nra\n");
}

void	conditions_min_b(swap_node **a, swap_node **b, int min_a, int min_b)
{
	if (!b || !*b)
		return ;
	while ((*b)->value != min_b && check_in_nodes(*b, min_b) == 0)
	{
		// && ft_find_nex_min(b, min_b - 1) == min_b
		rotate(b,"rb");
	}
	push(b,a,"\npa\n");
}