/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:47 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/25 15:42:25 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(char **menu, va_list args)
{
	int	size;

	size = 0;
	(*menu)++;
	if (**menu == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (**menu == 'c')
		size += ft_printchar((char) va_arg(args, int));
	else if (**menu == 'd' || **menu == 'i')
		size += ft_printeger(va_arg(args, int));
	else if (**menu == 'u')
		size += ft_printeger_unsig(va_arg(args, unsigned int));
	else if (**menu == 'x')
		size += ft_print_hex(va_arg(args, int), 0);
	else if (**menu == 'X')
		size += ft_print_hex(va_arg(args, int), 1);
	else if (**menu == 'p')
		size += ft_print_address(va_arg(args, unsigned long), 0);
	else
		size += ft_print_other_value(menu);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		size;
	va_list	args;
	char	*temp;

	size = 0;
	temp = (char *)str;
	va_start(args, str);
	while (*temp != '\0')
	{
		if (*temp == '%' && *(temp + 1) == '\0')
			return (-1);
		else if (*temp == '%')
		{
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
