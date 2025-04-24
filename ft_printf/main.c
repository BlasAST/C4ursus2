/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/24 02:06:29 by aisber           ###   ########.fr       */
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
}

int main(void)
{
	char *str = "Las, como estas?";
	char c = 'o';
	int	n = - - +  - 12;
	int h = - 123;
	int hex = - 12;
	spaces();
	ft_printf("\nTester printf:\n Enteros: %d \t\t Enteros: %i \n Enteros sin signo: %u \
		\t\t Strings: %s \t\t Caracteres: %c \t\t \nHexadecimales: \n\t\t \tLower: %x \
		\t\t \tUpper: %X \t\t \n\n Porcentaje: %%\t\t Puntero: %p\t\t \n\n\nOtras pruebas: \
		\n %^'a %k %N %%% %:% %%%d %\n\n \
		%% 1 %% d %%%d % 4 % 668 %     %% 8    h      o     % \n\n",
		n, n, h, str, c, hex, hex, &str);
	spaces();
	spaces();
	printf("\nTester printf:\n Enteros: %d \t\t Enteros: %i \n Enteros sin signo: %u \
		\t\t Strings: %s \t\t Caracteres: %c \t\t \nHexadecimales: \n\t\t \tLower: %x \
		\t\t \tUpper: %X \t\t \n\n Porcentaje: %%\t\t Puntero: %p\t\t \n\n\nOtras pruebas: \
		\n %^'a %k %N %%% %:% %%%d %\n\n \
		%% 1 %% d %%%d % 4 % 668 %     %% 8    h      o     % \n\n",
		n, n, h, str, c, hex, hex, &str);
	spaces();

	spaces();
	printf("Te juro por mi vida que %s me %%s%%s ja tocado %d los% % %  %%  -5 brazos %u no quiero nada más %c\n\n","el algorimto", 4, -6, 'A');
	ft_printf("Te juro por mi vida que %s me %%s%%s ja tocado %d los% % %  %%  -5 brazos %u no quiero nada más %c\n\n","el algorimto", 4, -6, 'A');
}