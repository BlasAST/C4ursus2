/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:47 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/26 19:48:04 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selection(char c, char *str)
{
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int ft_selection_bonus(char **menu, va_list args, va_list copy)
{
	int	size;

	size = 0;
	if (**menu == '-')
		size += ft_justify_left(menu, args);
	if (**menu == '0')
		size += ft_equals_cero(menu, copy);
	if (**menu == '.')
		size += ft_point(menu, copy);
	if (**menu == '#')
		size += ft_pound(menu, copy);
	if (**menu == '+')
		size += ft_plus(menu, copy);
	if (**menu == ' ')
	{
		ft_space(menu, args);
		ft_base(menu, args);
	}
		

	return (size);
}

int ft_selection_main(char **menu, va_list args)
{
	int	size;

	size = 0;
	if (**menu == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (**menu == 'c')
		size += ft_printchar((char) va_arg(args, int));
	else if (**menu == 'd' || **menu == 'i')
		size += ft_printeger(va_arg(args, int));
	else if (**menu == 'u')
		size += ft_printeger_unsig(va_arg(args, unsigned int));
	else if (**menu == 'x' || **menu == 'X')
		size += ft_print_hex(va_arg(args, int), **menu);
	else if (**menu == 'p')
		size += ft_print_address(va_arg(args, unsigned long), 0);
	else if (**menu == '%')
		size += ft_printchar('%');
	return (size);
}

int	ft_base(char **menu, va_list args)
{
	int	size;
	va_list	copy;

	size = 0;
	va_copy(copy, args);
	if (ft_selection(**menu, "-0. #+"))
		size += ft_selection_bonus(menu, args, copy);
	else if (ft_selection(**menu, "scdiuxXp%"))
		size += ft_selection_main(menu, args);
	else
	{
		size += ft_printchar('%');
		if (*(*menu - 1) == ' ')
			size += ft_printchar(' ');
		size += ft_printchar(**menu);
	}
	return (size);
}


int	ft_printf(const char *str, ...)
{
	int		size;
	va_list	args;
	char *temp;

	size = 0;
	temp = (char *)str;
	va_start(args, str);
	while (*temp != '\0')
	{
		if (*temp == '%')
		{
			temp++;
			size += ft_base(&temp, args);
		}
		else
		{
			write(1, temp, 1);
			size++;
		}
		temp++;
	}
	va_end(args);
	return (size);
}
