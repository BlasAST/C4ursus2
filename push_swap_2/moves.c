/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:25 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/04 12:55:29 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(swap_node **from, swap_node **to, char *str_print)
{
	swap_node *temp;

	if (!*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	swap(swap_node	**node, char *str_print)
{
	swap_node *temp;

	if (!node || !(*node)->next)
		return ;
	temp = *node;
	*node = (*node)->next;
	temp->next = (*node)->next;
	(*node)->next = temp;
}

void	rotate(swap_node **node, char *str_print)
{
	swap_node *temp;
	swap_node *iter;

	iter = *node;
	temp = *node;
	(*node) = (*node)->next;
	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(swap_node **node, char *str_print)
{
	swap_node *temp;
	swap_node *iter;

	iter = *node;
	while (iter->next->next != NULL)
	{
		iter = iter->next;
	}
	temp = iter->next;
	iter->next = NULL;
	temp->next = *node;
	*node = temp;
}