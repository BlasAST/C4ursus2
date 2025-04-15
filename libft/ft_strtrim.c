/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:06:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:36:48 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_str(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_t;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_in_str(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (s1[end] != s1[start] && ft_in_str(s1[end - 1], set))
		end--;
	s_t = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!s_t)
		return (NULL);
	i = 0;
	while (start < end)
		s_t[i++] = s1[start++];
	s_t[i] = '\0';
	return (s_t);
}

/* 
	OBtiene la string a recortar por delante y por detras
	los caracteres que se deben eliminar
	! Return null si falla asignación de memoria
	? Elimina caracteres de la string del principio y del final de s1
		*Recorrer la string desde el principio
		* buscando coincidencias con los caracteres que se buscan (
			*crear funcion para recorrer los
			*caracteres)
		* Mientras sean los caracteres del set avanzar y guardar el
			* inicio de la string
		! SI el inicio es el final porque todos los caracteres son 
			! \0 devolver eso
		*Calcular la longitud de la string hasta el final desde don
			*de se quedo
		* Recorrerlo hacia atras hasta que sea igual y detecte algu
			*n caracter del set al final
		* asignar memoria
			*
		* Recorrer desde el inicio que nos quedo hasta el final que
			* tambien nos quedo.
		* Añadir \0
		!Lo que se ha hecho es restar el start a end +1 para el \0
		!De esa forma ya se pone \0 si start - end  = 0 + 1
 */