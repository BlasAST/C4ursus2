/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:05:27 by aisber            #+#    #+#             */
/*   Updated: 2025/09/11 14:03:02 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nodes_in_order(t_swap_node **node)
{
	int			i;
	t_swap_node	*temp;

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

int	bits_need(int max)
{
	int	bit;

	bit = 0;
	while ((max >> bit) != 0)
		bit++;
	return (bit);
}

void	order_three(t_swap_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second > third)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (first > third && third > second)
		rotate(a, "ra");
	else if (first < second && first > third)
		reverse_rotate(a, "rra");
	else if (first > second && second < third && first < third)
		swap(a, "sa");
	else if (first < second && second > third && first < third)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
}

void	order_five(t_swap_node **a, t_swap_node **b)
{
	int	min;
	int	pos;
	int	size;

	while (size_nodes(*a) > 3)
	{
		min = ft_find_min(a);
		pos = find_index(*a, min);
		if (pos <= size_nodes(*a) / 2)
			while ((*a)->value != min)
				reverse_rotate (a, "rra");
		else
			while ((*a)->value != min)
				rotate(a, "ra");
		push(a, b, "pb");
	}
	order_three(a);
	while (*b)
		push(b, a, "pa");
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

void	order_max_order(t_swap_node **b, t_swap_node **a)
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

void	order_chunks(t_swap_node **a, t_swap_node **b, int size)
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
			push(a, b, "pb");
			if (*b && (*b)->index < chunk_max - chunk_size / 2 \
				&& (*b)->index <= i)
				rotate(b, "rb");
			i++;
		}
		else
			rotate(a, "ra");
		if (i >= chunk_max)
			chunk_max += chunk_size;
	}
	order_max_order(b, a);
}

void	generate_orders(t_swap_node **a, t_swap_node **b, int size)
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
}

int	count_repeats(t_swap_node *a, int value)
{
	int	count;

	count = 0;
	while (a != NULL)
	{
		if (a->value == value)
			count++;
		a = a->next;
	}
	return (count);
}

int	find_nodes_repeat(t_swap_node *a)
{
	t_swap_node	*temp;

	temp = a;
	while (temp != NULL)
	{
		if (count_repeats(a, temp->value) > 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	main(int argn, char **args)
{
	int			error;
	t_swap_node	*a;
	t_swap_node	*b;
	int			size;
	int			max_bits;

	b = NULL;
	error = add_values(&a, argn, args);
	if (error == 1 || find_nodes_repeat(a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	add_index(&a);
	size = size_nodes(a);
	max_bits = bits_need(size - 1);
	generate_orders(&a, &b, size);
	return (0);
}
