/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:15:04 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/12 13:29:12 by bsiguenc         ###   ########.fr       */
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

int	return_error(char *str)
{
	write(2, str, ft_strlen(str));
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

int	create_new_node(int i, int len, t_swap_node **new_node)
{
	if (i + 1 != len)
	{
		(*new_node)->next = create_node();
		if ((*new_node)->next == NULL)
			return (return_error("Error create node"));
		*new_node = (*new_node)->next;
	}
	return (0);
}

int	add_values(t_swap_node **node, int len, char **args)
{
	int			i;
	int			valid_value;
	int			index;
	t_swap_node	*new_node;

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
		if (create_new_node(i, len, &new_node) == 1)
			return (1);
		i++;
		index++;
	}
	return (0);
}
