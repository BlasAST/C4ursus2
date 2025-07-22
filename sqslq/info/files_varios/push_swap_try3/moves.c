/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:25 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/12 00:46:07 by aisber           ###   ########.fr       */
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
	ft_printf("%s\n", str_print);
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
	ft_printf("%s\n", str_print);
}

void	rotate(swap_node **node, char *str_print)
{
	swap_node *temp;
	swap_node *iter;

	iter = *node;
	temp = *node;
	if ((*node)->next == NULL)
		return ;
	(*node) = (*node)->next;
	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = temp;
	temp->next = NULL;
	ft_printf("%s\n", str_print);
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
	ft_printf("%s\n", str_print);
}