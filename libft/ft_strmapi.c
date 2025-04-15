/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:12:01 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 15:25:54 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* 
	Aplicar la funcion f a cada caracter de la cadena s
	Se pasa su indice
	El caracter como segundo argumento
	Creación de nueva cadena con malloc
	Recoge las sucesivas aplicaciones de f
	! Devolver null si falla la reserva de memoria
		*Declarar un iterador para coger el indice
		*Obtener longitud de la cadena
		*Crear la string que almacena el resultado de la funcion
		*Recorrerlo con el indice
		*Aplicar la funcion a cada caracter
 */