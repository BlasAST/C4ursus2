/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:15:04 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/03 14:48:01 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_nodes(swap_node **node, char *str_print)
{
	swap_node *temp;

	temp = *node;
	while (temp != NULL)
	{
		ft_printf("Index %d: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
	ft_printf("%s", str_print);
}