/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:15:55 by aisber            #+#    #+#             */
/*   Updated: 2025/04/20 21:52:46 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
/* 
int	ft_print_str(char *str)
{
	printf("%s", str);
	return (0);
} */

int	ft_params(char *menu, va_list args)
{
	if (*menu == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*menu == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
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

int main(void)
{
	ft_printf("como tu te llama yo no %s %c %s %s", "Hola que tal estas", 'c' ,"aaa");
}