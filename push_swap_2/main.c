/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/04 14:29:16 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argn, char **args)
{
	int	error;
	swap_node *a;
	swap_node *b;

	error = check_args(args);
	if (error == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	add_values(&a, argn, args);
	show_nodes(&a, "HOla");
	// a->value = 128;
	// a->index = 1;
	// b = (swap_node *)malloc(sizeof(swap_node));
	// b->value = 123123;
	// b->index = 2;
	// swap_node *c;
	// swap_node *d;
	// c = (swap_node *)malloc(sizeof(swap_node));
	// c->value = 919128;
	// c->index = 3;
	// d = (swap_node *)malloc(sizeof(swap_node));
	// d->value = 6212362;
	// d->index = 4;
	// push(&b,&a, "Hola");
	// push(&c,&a, "Hola");
	// push(&d,&a, "Hola");
	// show_nodes(&a, "HOla");
	// swap(&a, "\n");
	// show_nodes(&a, "HOla");
	// rotate(&a,"\n");
	// show_nodes(&a, "HOla");
	// reverse_rotate(&a,"\n");
	// show_nodes(&a, "HOla");
}