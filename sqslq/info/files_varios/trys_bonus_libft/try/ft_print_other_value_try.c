/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other_value_try.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:09 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/25 12:12:46 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_porcent(char **c)
{
	if (**c == '%' && *(*c + 1) == '%')
	{
		ft_printchar(**c);
	}
	else
		ft_printchar(**c);
	return (1);
}

static int	ft_other(char **c)
{
	ft_printstr("% ");
	ft_printchar(**c);
	return (2);
}


int	ft_find_bonus(char **c)
{
	int	size;

	size = 0;
	while (**c  == ' ' && (**c != '-' || **c != '0' || **c != '.' || **c != '#' || **c != '+'))
	{
		(*c)++;
	}
	if (ft_isalnum(**c))
	{
		size += ft_other(c);
	}
	else if (**c == '%')
		size += ft_porcent(c);
	else if (**c == '-')
		size += ft_printchar('-');
	else if (**c == '+')
		size += ft_printchar('+');
	else
		size += ft_printchar(**c);
		
	
	return (size);
}

int	ft_print_other_value(char **c, va_list args)
{
	int	size;

	size = 0;
	if (ft_isalnum(**c))
		size += ft_other(c);
	else if (**c == '%')
		size += ft_porcent(c);
	else
		ft_find_bonus(c);
	if (args)
		return (1);
	
	return (0);
}
