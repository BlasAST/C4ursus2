/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:05:27 by aisber            #+#    #+#             */
/*   Updated: 2025/07/22 18:38:40 by bsiguenc         ###   ########.fr       */
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

int	bits_need(int max)
{
	int	bit;

	bit = 0;
	while ((max >> bit) != 0)
		bit++;
	return (bit);
}

int	main(int argn, char **args)
{
	int	error;
	swap_node *a;
	swap_node *b;
	int	size;
	int	max_bits;
	int	i;
	int	j;

	b = NULL;
	error = add_values(&a, argn, args);
	if (error == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	add_index(&a);
	size = size_nodes(a);
	max_bits = bits_need(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->index >> i) & 1) == 0 )
				push(&a, &b, "pb");
			else
				rotate(&a, "ra");
			j++;
		}
		while (b)
			push(&b, &a, "pa");
		i++;
	}
	// show_nodes(&a, "A:");
}