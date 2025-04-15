/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:16 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:32:05 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* 
	A cada caracter de "s" aplica la funcion "f" indicando 
	el indice del caracter de "s"
	y la dirección del caracter.
	? Podra modificarse si es necesario ?
	!No retorna nada
	
		*Recorrer la string s
		*Pasar a f la dirección de s == &s
		*no retornar nada ?
 */