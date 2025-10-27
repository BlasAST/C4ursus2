/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:25 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/11 13:57:21 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_swap_node **from, t_swap_node **to, char *str_print)
{
	t_swap_node	*temp;

	if (!*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	ft_printf("%s\n", str_print);
}

void	swap(t_swap_node	**node, char *str_print)
{
	t_swap_node	*temp;

	if (!node || !(*node)->next)
		return ;
	temp = *node;
	*node = (*node)->next;
	temp->next = (*node)->next;
	(*node)->next = temp;
	ft_printf("%s\n", str_print);
}

void	rotate(t_swap_node **node, char *str_print)
{
	t_swap_node	*temp;
	t_swap_node	*iter;

	if (!node || !*node || !(*node)->next)
		return ;
	iter = *node;
	temp = *node;
	(*node) = (*node)->next;
	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = temp;
	temp->next = NULL;
	ft_printf("%s\n", str_print);
}

void	reverse_rotate(t_swap_node **node, char *str_print)
{
	t_swap_node	*temp;
	t_swap_node	*iter;

	if (!node || !*node || !(*node)->next)
		return ;
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
