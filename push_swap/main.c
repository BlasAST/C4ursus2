/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:05:27 by aisber            #+#    #+#             */
/*   Updated: 2025/07/17 00:50:46 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nodes_in_order(swap_node **node)
{
	int	i;
	swap_node *temp;

	if (!*node)
		return (1);
	temp = (*node);

	i = 0;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	ft_filter_swap(swap_node **node, swap_node *node_b)
{
	if (ft_nodes_in_order(node) == 1 || node_b != NULL)
		return (1);
	return (0);
}

int	main(int argn, char **args)
{
	int	error;
	swap_node *a;
	swap_node *b;
	int	min_a;
	int	min_b;
	int	i;

	b = NULL;
	error = add_values(&a, argn, args);
	if (error == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	add_index(&a);
	show_nodes(&a, "A:");
}