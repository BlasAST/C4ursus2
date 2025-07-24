/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:05:27 by aisber            #+#    #+#             */
/*   Updated: 2025/07/24 22:07:29 by aisber           ###   ########.fr       */
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

void	order_three(swap_node **a)
{
	int	first;
	int	second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third)
		swap(a, "sa");
	else if (first > second && second > third)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (first > second && second < third)
		rotate(a, "ra");
	else if (first < second && second > third && first < third)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, "rra");
}

void	order_five(swap_node **a, swap_node **b)
{
	int	min;

	while (size_nodes(*a) > 3)
	{
		min = ft_find_min(a);
		while ((*a)->value != min)
			rotate(a ,"ra");
		push(a, b, "pb");
	}
	order_three(a);
	while (*b)
		push(b, a, "pa");
}

void 	order_chunks()
{
	ft_printf("Esto ya toca organizarlo con chunks");
}

void	generate_orders(swap_node **a, swap_node **b, int size, int m_bits)
{
		if (ft_nodes_in_order(a) != 0)
		{
			if (size == 2)
				swap(a, "sa");
			else if (size == 3)
				order_three(a);
			else if (size <= 5)
				order_five(a, b);
			else
				order_chunks();
		}
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
	generate_orders(&a, &b, size, max_bits);
	// show_nodes(&a, "A:");
}