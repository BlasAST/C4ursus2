/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/04 14:29:16 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_filter_swap(swap_node **node, int len)
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
	if (i != len - 1)
		return (1);
	return (0);
}

int main(int argn, char **args)
{
	int	error;
	swap_node *a;
	swap_node *b;

	error = add_values(&a, argn, args);
	if (error == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	push(&a, &b, "pb");
	push(&a, &b, "pb");
	while (ft_filter_swap(&a, argn) == 1)
	{
		push(&b, &a, "pb");
		push(&b, &a, "pb");
		show_nodes(&a, "A");
		show_nodes(&b, "B");
	}
	
}