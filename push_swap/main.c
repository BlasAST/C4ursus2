/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:02:55 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/06/23 18:24:25 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argn, char **args)
{
	int	*a;
	int	*b;

	argn -= 1;
	a = ft_putargs(argn, args);
	b = (int *) malloc (sizeof(int) * (argn));
	if (!b)
		return (0);
	ft_print_arr(a, argn);
	swap_a(a);
	ft_print_arr(a, argn);
	push_b(b,a,argn);
	push_b(b,a,argn);
	push_a(a,b,argn);
	push_b(b,a,argn);
	push_b(b,a,argn);
	ft_print_arr(a, argn);
	ft_print_arr(b, argn);
	return (0);
}
