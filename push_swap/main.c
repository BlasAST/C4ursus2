/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:02:55 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/06/27 15:41:45 by bsiguenc         ###   ########.fr       */
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
	int	i;
	int	smaller;

	argn -= 1;
	a = ft_putargs(argn, args);
	b = (int *) malloc (sizeof(int) * (argn));
	if (!b)
		return (0);
	i = 0;
	
	return (0);
}

/* CODIGO VALIDO 1.1 con indice:
while (ft_filter_swap(a, argn) == 1)
{
	if (ft_len_arr(a) != 0)
	{
		smaller = a[0];
		smaller = ft_find_smaller(a, &smaller);
		while (i != smaller)
		{
				rotate_a(a, argn);
			i++;
		}
		i = 0;
		push_b(b, a, argn);
	}
	else
	{
		while (i < argn)
		{
			push_a(a,b,argn);
			i++;
		}
	}
	// show(a,b,argn);
} */

/*  CODIGO VALIDO 1:

	while (ft_filter_swap(a, argn) == 1)
	{
		if (ft_len_arr(a) != 0)
		{
			smaller = a[0];
			smaller = ft_find_smaller(a, &smaller);
			while (a[0] != smaller)
			{
				rotate_a(a, argn);
			}
			push_b(b, a, argn);
		}
		else
		{
			while (i < argn)
			{
				push_a(a,b,argn);
				i++;
			}
		}
		// show(a,b,argn);
	} */

/*	CODIGO VALIDO 2
	while (ft_filter_swap(a, argn) == 1)
	{
		if (a[0] > a[1] && a[1])
			rotate_a(a, argn);
		else
		{
			push_b(b,a, argn);
		}
		if (ft_len_arr(a) == 0)
		{
			while (i < argn)
			{
				push_a(a,b,argn);
				i++;
			}
			i = 0;
		}
		show(a,b,argn);
	} */
