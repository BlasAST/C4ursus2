/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:02:55 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/06/25 14:23:27 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(int *a, int *b, int argn)
{
	ft_printf("\nArray a:\n");
	ft_print_arr(a, argn);
	ft_printf("\nArray b:\n");
	ft_print_arr(b, argn);
}

int	main(int argn, char **args)
{
	int	*a;
	int	*b;

	argn -= 1;
	a = ft_putargs(argn, args);
	b = (int *) malloc (sizeof(int) * (argn));
	if (!b)
		return (0);
	// show(a,b,argn);
	// push_b(b, a,argn);
	// push_b(b, a,argn);
	// push_b(b, a,argn);
	// show(a,b,argn);
	// reverse_rotate_ab(a,b,argn);
	// show(a,b,argn);
	while (ft_filter_swap(a) == 1)
	{
		push_b(b,a,argn);
		show(a,b,argn);
	}
	return (0);
}
