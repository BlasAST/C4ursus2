/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:05:27 by aisber            #+#    #+#             */
/*   Updated: 2025/08/09 19:25:41 by aisber           ###   ########.fr       */
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
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
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

int get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 7);
	else
		return (size / 11);
}

int	get_max_index(swap_node *node)
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

int	find_index(swap_node *node, int max)
{
	int pos;

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
void	order_max_order(swap_node **b, swap_node **a)
{
	int	max;
	int	pos;
	int	len;

	while (*b)
	{
		max = get_max_index(*b);
		pos = find_index(*b, max);
		len = size_nodes(*b);
		if (pos < (len / 2))
			while ((*b)->index != max)
				rotate(b, "rb");
		else
			while ((*b)->index != max)
				reverse_rotate(b, "rrb");
		push(b, a, "pa");
	}
	
}

void 	order_chunks(swap_node **a, swap_node **b, int size)
{
	int	i;
	int	chunk_size;
	int	chunk_max;

	chunk_size = get_chunk_size(size);
	chunk_max = chunk_size;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= chunk_max)
		{
			push(a,b,"pb");
			if (*b && (*b)->index < chunk_max - chunk_size / 2 && (*b)->index <= i)
				rotate(b, "rb");
			i++;
		}
		else
			rotate(a, "ra");
		if (i >= chunk_max)
			chunk_max += chunk_size;
	}
	order_max_order(b,a);
}

void	generate_orders(swap_node **a, swap_node **b, int size)
{
		if (ft_nodes_in_order(a) == 0)
		{
			if (size == 2)
				swap(a, "sa");
			else if (size == 3)
				order_three(a);
			else if (size <= 5)
				order_five(a, b);
			else
				order_chunks(a, b, size);
		}
		// show_nodes(a, "A:");
		// show_nodes(b, "B:");
}

int	main(int argn, char **args)
{
	int	error;
	swap_node	*a;
	swap_node	*b;
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
	generate_orders(&a, &b, size);
}