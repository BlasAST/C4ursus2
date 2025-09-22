/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:15:04 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/22 13:11:26 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clean_nodes(t_swap_node **node)
{
	t_swap_node	*temp;

	while (*node != NULL)
	{
		temp = (*node);
		*node = (*node)->next;
		free(temp);
	}
	return (1);
}

int	return_error(char *str, t_swap_node **node)
{
	write(2, str, ft_strlen(str));
	if (*node)
		clean_nodes(node);
	return (1);
}

t_swap_node	*create_node(void)
{
	t_swap_node	*new;

	new = (t_swap_node *) malloc(sizeof(t_swap_node));
	if (!new)
	{
		write(2, "Error:", 6);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

int	add_values(t_swap_node **node, int len, char **args)
{
	int			i;
	int			valid_value;
	t_swap_node	*new_node;

	i = 1;
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
				return (return_error("Error create node", node));
			new_node = new_node->next;
		}
		i++;
	}
	return (0);
}
