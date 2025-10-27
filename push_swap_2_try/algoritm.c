/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:07:54 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/11 14:18:21 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
