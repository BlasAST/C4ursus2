/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:06:06 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:41:13 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Localiza la primera ocurrencia de s2 en s1 sin buscar en más
	de la len que se nos pasa
	por parametro.
	Pone algo raro de los caracteres de despues de \0 no se buscan.
	si s2 es vacio se retorna s1
	si s2 no esta en s1 se retorna null
	si no el primer caracter es la el puntero a la primera 
	ocurrencia de s2
	! EN el segundo while antes de acceder a los valores de 
	s1 y s2 comprobar antes si i + j
	! es menor que len dado que puede fallar accediendo a 
	memoria no valida
	
 */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i < len && s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while ((i + j) < len && s1[i + j] == s2[j] && s1[i + j] != '\0')
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *a = "Hola no buenas noches";
	char *b = "no";
	char *c = ft_strnstr(a,b,21);
	printf("%s", c);
}
*/