/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:28:50 by marvin            #+#    #+#             */
/*   Updated: 2025/10/27 18:00:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_swap_node **node)
{
	*node = (t_swap_node *)malloc(sizeof(t_swap_node));
	if (!(*node))
		clean_nodes(*node, 1, "Error en la creación de nodos");
}

int	main(int argn, char **args)
{
	t_swap_node	*a;
	t_swap_node	*b;

	init_node(&a);
	add_values(args, &a);
}