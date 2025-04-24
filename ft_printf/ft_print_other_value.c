/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:09 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/24 13:32:24 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_porcent(char **c)
{
	if (**c == '%' && (*(*c + 1) == '%' || *(*c + 1) == ' '))
		ft_printchar('%');
	else
		ft_printchar('%');
	return (1);
}

static int	ft_space(char **c)
{
	int	i;

	i = 0;
	while (**c == ' ')
	{
		(*c)++;
		i++;
	}
	if (**c != '%')
	{
		ft_printstr("% ");
		ft_printchar(**c);
	}
	else
	{
		ft_printchar('%');
		i++;
	}
	return (i);
}

static int	ft_other(char **c)
{
	ft_printchar('%');
	ft_printchar(**c);
	return (2);
}

int	ft_print_other_value(char **c, va_list args)
{
	int	size;

	size = 0;
	if (**c == '%')
		size += ft_porcent(c);
	else if (**c == ' ')
		size += ft_space(c);
	else if (**c != '-' || **c != '0' || **c != '.' || **c != '#' || **c != '+')
		size += ft_bonus_printf(c, args);
	else
		size += ft_other(c);
	return (size);
}
