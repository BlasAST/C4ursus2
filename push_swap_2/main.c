/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/08 19:47:19 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_filter_swap(swap_node **node, swap_node *node_b, int len)
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
	if (node_b != NULL)
		return (1);
	return (0);
}

int main(int argn, char **args)
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
	// show_nodes(&a, "A");
	// show_nodes(&b, "B");
	// push(&a, &b, "pb");
	// push(&a, &b, "pb");
	min_a = ft_find_min(&a);
	min_b = ft_find_min(&b);
	// ft_printf("%d\n", min_b);
	i = 0;
	push(&a, &b, "pb");
	while (i < 20)
	{
		if (a)
			min_a = ft_find_nex_min(&a, min_a);
		if (b)
			min_b = ft_find_nex_min(&b, min_b);
		ft_printf("%d-%d\n", min_a, min_b);
		i++;
	}
	/* while (ft_filter_swap(&a, b, argn) == 1)
	{
		show_nodes(&a, "A");
		show_nodes(&b, "B");
		// push(&a, &b, "pb");
	} */
}