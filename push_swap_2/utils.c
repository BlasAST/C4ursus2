/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:15:04 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/04 14:09:12 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

swap_node	*create_node()
{
	swap_node *new;
	new = (swap_node*) malloc(sizeof(swap_node));
	new->next = NULL;
	return new;
}

int	add_values(swap_node **node, int len, char **args)
{
	int	i;
	int	valid_value;
	swap_node *new_node;

	i = 1;
	new_node = create_node();
	*node = new_node;
	while (i < len)
	{
		new_node->index = i;
		valid_value = check_args(args[i], &new_node);
		if (valid_value == 1)
			return (1);
		if (i + 1 != len)
		{
			new_node->next = create_node();
			new_node = new_node->next;
		}
		i++;
	}
	return (0);
}

void	show_nodes(swap_node **node, char *str_print)
{
	swap_node *temp;

	temp = *node;
	while (temp != NULL)
	{
		ft_printf("Index %d: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
	ft_printf("\n\n");
}

// FIltrar palabras
// Que no sea vacio
// Mexlados con comiilas o sin comillas
// validar más y min
// SOlo un signo