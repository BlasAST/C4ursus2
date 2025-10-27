/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:40:34 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 10:08:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_exit(int code, char *msg)
{
	ft_printf("%s", msg);
	exit(code);
}

void	clean_nodes(t_swap_node *node, int code, char *msg)
{
	t_swap_node *temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	ft_printf("%s", msg);
	exit(code);
}