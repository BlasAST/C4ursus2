/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/23 01:13:10 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaces()
{
	int	i;

	i = 0;
	ft_printchar('\n');
	ft_printchar('\n');
	while (i < 20)
	{
		ft_printchar('-');
		i++;
	}
	ft_printchar('\n');
	ft_printchar('\n');
}

int main(void)
{
	char *str = "Las, como estas?";
	char c = 'o';
	int	n = - - +  - 12;
	int h = - 123;
	int hex = - 12;
	spaces();
	ft_printf("Tester ft_printf: \n\n Enteros: %d \n\n Enteros: %i \n\n Enteros sin signo: %u \
		\n\n Strings: %s \n\n Caracteres: %c \n\n Hexadecimales: \n\n \tLower: %x \
		\n\n \tUpper: %X \n\n Porcentaje: %%\n\n Puntero: %p\n\n", n, n, h, str, c, hex, hex, &str);
	spaces();
	printf("Tester printf: \n\n Enteros: %d \n\n Enteros: %i \n\n Enteros sin signo: %u \
		\n\n Strings: %s \n\n Caracteres: %c \n\n Hexadecimales: \n\n \tLower: %x \
		\n\n \tUpper: %X \n\n Porcentaje: %%\n\n Puntero: %p \n\n", n, n, h, str, c, hex, hex, &str);
	spaces();
}