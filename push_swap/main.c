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
	ft_printf("++++++++");
	ft_printf("\nArray a:\n");
	ft_print_arr(a, argn);
	ft_printf("\nArray b:\n");
	ft_print_arr(b, argn);
	ft_printf("++++++++\n");
}

int	main(int argn, char **args)
{
	int	*a;
	int	*b;
	int	i;
	int	smaller;
	int	smaller_2;

	argn -= 1;
	a = ft_putargs(argn, args);
	b = (int *) malloc (sizeof(int) * (argn));
	if (!b)
		return (0);
	i = 0;
	// while (ft_filter_swap(a, argn) == 1)
	while (i < 12)
	{
		smaller = ft_find_smaller(a, smaller);
		smaller_2 = ft_find_smaller(b, smaller_2);
		if (smaller < smaller_2)
		{
			if (a[0] == smaller)
				rotate_a(a, argn);
			else if (a[1] == smaller)
			{
				swap_a(a);
				rotate_a(a, argn);
			}
			else
				push_b(b, a, argn);
		}
		else
		{
			if (b[0] == smaller_2)
				push_a(a,b,argn);
			else
				rotate_b(b, argn);
		}
		show(a,b,argn);
		i++;
	}
	
	return (0);
}

/* Intento de algoritmo:
while (ft_filter_swap(a, argn) == 1)
	{
		if (ft_len_arr(a) != 0 && ft_len_arr(b) != 0)
		{
			smaller = ft_find_smaller(a);
			smaller_2 = ft_find_smaller(b);
			i = 0;
			if (smaller < smaller_2)
			{
				if (a[0] == smaller)
					rotate_a(a, argn);
				else if(a[1] == smaller)
					swap_a(a);
				else
					push_b(b, a, argn);
			}
			else
			{
				if (b[0] == smaller_2)
					push_a(a, b, argn);
				else
					rotate_b(b, argn);
			}
		}
		else if (ft_len_arr(a) != 0)
		{
			smaller = ft_find_smaller(a);
			if (a[0] == smaller)
				rotate_a(a, argn);
			else
				push_b(b, a, argn);
		}

		show(a,b,argn);
	}
*/

/* Mejor codigo momentaneo:
while (ft_filter_swap(a, argn) == 1)
		{
			smaller = a[0];
			smaller = ft_find_smaller(a, &smaller);
			if (a[0] == a[smaller])
				push_b(b ,a, argn);
			else if (smaller > ft_len_arr(a) / 2)
				reverse_rotate_a(a, argn);
			else
				rotate_a(a, argn);
			if (ft_len_arr(a) == 0)
			{
								
				while (i < argn)
				{
					push_a(a,b,argn);
					i++;
				}
			}
		}

*/

/*Codigo no tan valido:
	while (ft_filter_swap(a, argn) == 1)
		{
			if (ft_len_arr(a) != 0)
			{
				smaller = a[0];
				smaller = ft_find_smaller(a, &smaller);
				i = 0;
				while (i != smaller)
				{
					if (smaller == 1)
					{
						swap_a(a);
						break;
					}
					else if (smaller == (ft_len_arr(a)))
					{
						reverse_rotate_a(a, argn);
						break;
					}
					else
						rotate_a(a, argn);
					i++;
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
		}*/

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
