/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:08 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:37:39 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

/* 
	Enviar el numero al fd por ello hay que convertirlo a string
	Recorrer el numero dividiendolo entre 10
	Ir uniendo el modulo que formemos y añadir \0

		*Recorrer el numero
		*Calcular el tamaño
		*Introducirlo invertido
		*Usar write
		*maneja negativos
 */