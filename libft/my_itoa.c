/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:18:36 by blas              #+#    #+#             */
/*   Updated: 2025/04/15 00:48:39 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Int to char
	* 1.Recibe un int a convertir
	* 2.Realizar casteo a long para evitar errores
	* 5.Comprobar signo dado que debe mostrarse
	*	 en caso de ser negativo (funcion adicional para 5 y 3)
	*	 comprobar si es 0;
	* 3.Calcular longitud 
	* /-/Poner negativo en la longitud total
	* 4.Reservar memoria con la longitud (malloc)
	*	4.1.Devolver null en caso de error
	*	4.2 Continuar en caso de error
	* 10. Primero poner signo y manejar el 0
	* 6. Al hacerlo se hará al reves por lo que sería mejor empezar desde el final
	* 7. Unir a la string
	* 8. Terminar la string con \0
	*9. Devolver la string valida.
*/

static int ft_count_size(int n)
{
	size_t neg;
	size_t len;

	neg = 0;
	len = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	if (n == 0)
		return (1 + neg);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len + neg);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t len_nb;
	char *str;

	nb = n;
	len_nb = ft_count_size(n);
	str = (char *)malloc(sizeof(char) * (len_nb + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	str[len_nb] = '\0';
	while (nb > 0)
	{
		str[--len_nb] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int main(void)
{
	printf("%s", ft_itoa(-12345));
}