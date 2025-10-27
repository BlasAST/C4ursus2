/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:29:16 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 10:50:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(char *arg)
{
	int	i;

	i = 0;
	while(arg[i] == ' ' && arg[i] != '\0')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
	}
	while (arg[i])
	{
		// ft_printf("Aqui: %c", arg[i]);
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (i);
}

int	check_size_numbers(char *arg)
{
	int	i;
	int	size;
	int	numbers;
	int	count_nb;

	i = 0;
	count_nb = 0;
	while (arg[i])
	{
		while (arg[i] != ' ' && arg[i] != '\0')
			i++;
		size = valid_number(&(arg[i]));
		if (size == -1)
			return (-1);
		count_nb++;
		i += size;
	}
	return (count_nb);
}

void	check_arg(char *arg)
{
	int	count;

	count = check_size_numbers(arg);
	if ( count == 1)
	{
		ft_printf("%d", count);
	}
	else if (count > 1)
	{
		ft_printf("%d", count);
	}
	else
	{
		ft_printf("%d", count);
		send_exit(1, "Error al procesar la cadena");
	}
		
}