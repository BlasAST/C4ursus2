/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:47 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/21 18:58:05 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params(char *menu, va_list args)
{
	if (*menu == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*menu == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*menu == 'd')
		ft_printdec(va_arg(args, int));
	else if (*menu == 'i')
		return (1);
	else if (*menu == 'u')
		return (1);
	else if (*menu == 'x')
		return (1);
	else if (*menu == 'X')
		return (1);
	else if (*menu == '%')
		write(1, "%", 1);
	else
	{
		write(1, "%", 1);
		write(1, menu, 1);
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			ft_params((char *)str + 1, args);
			str++;
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(args);
	return (1);
}
