/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:15:04 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/08 13:08:49 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clean_nodes(swap_node **node)
{
	swap_node *temp;

	while (*node != NULL)
	{
		temp = (*node);
		*node = (*node)->next;
		free(temp);
	}
	return (1);
}

int	return_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

swap_node	*create_node()
{
	swap_node *new;
	new = (swap_node*) malloc(sizeof(swap_node));
	if (!new)
	{
		write(2, "Error:", 6);
		return (NULL);
	}
	new->next = NULL;
	return new;
}

int	add_values(swap_node **node, int len, char **args)
{
	int	i;
	int	valid_value;
	int	index;
	swap_node *new_node;

	i = 1;
	index = 1;
	new_node = create_node();
	if (new_node == NULL)
		return (1);
	*node = new_node;
	while (i < len)
	{
		valid_value = check_args(args[i], &new_node);
		if (valid_value == 1)
			return (clean_nodes(node));
		if (i + 1 != len)
		{
			new_node->next = create_node();
			if (new_node->next == NULL)
				return (return_error("Error create node"));
			new_node = new_node->next;
		}
		i++;
		index++;
	}
	return (0);
}

void	show_nodes(swap_node **node, char *str_print)
{
	swap_node *temp;

	temp = *node;
	ft_printf("%s", str_print);
	while (temp != NULL)
	{
		ft_printf("Indice: %d -> %d\n", temp->index, temp->value);
		temp = temp->next;
	}
	ft_printf("\n\n");
}