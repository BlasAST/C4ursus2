/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:47 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/22 15:36:03 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(char *menu, va_list args)
{
	int	size;

	size = 0;
	if (*menu == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (*menu == 'c')
		size += ft_printchar(va_arg(args, int));
	else if (*menu == 'd')
		size += ft_printdec(va_arg(args, double));
	else if (*menu == 'i')
		size += ft_printeger(va_arg(args, int));
	else if (*menu == 'u')
		return (1);
	else if (*menu == 'x')
		return (1);
	else if (*menu == 'X')
		return (1);
	else if (*menu == '%')
		size += ft_printchar('%');
	else
	{
		size += ft_printchar('%');
		size += ft_printchar(*menu);
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int	size;
	va_list args;

	size = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			size = ft_base((char *)str + 1, args);
			str++;
		}
		else
		{
			write(1, str, 1);
			size++;
		}
		str++;
	}
	va_end(args);
	return (size);
}
