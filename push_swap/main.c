/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:05:27 by aisber            #+#    #+#             */
/*   Updated: 2025/09/11 14:11:29 by bsiguenc         ###   ########.fr       */
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

	b = NULL;
	error = add_values(&a, argn, args);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (find_nodes_repeat(a) == 1)
	{
		write(2, "Error\n", 6);
		clean_nodes(&a);
		return (1);
	}
	add_index(&a);
	size = size_nodes(a);
	generate_orders(&a, &b, size);
	clean_nodes(&a);
	clean_nodes(&b);
	return (0);
}
