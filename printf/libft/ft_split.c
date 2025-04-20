/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:56:58 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 15:01:25 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	#.Consiste en crear un array de strings de una string
	1. Recibir la cadena y el delimitador
	2.Instrucciones
		* 2.0 Declarar len de la string, char * puntero, char **punteros;
		* 2.1 Recorre string en busca del delimitador (fa)
		* 2.2. Hacer un char ** con la cantidad de elementos
		* 2.3 Recorrer la string
		* 2.4 Calcular el size hasta obtener la longitud de la string
		* 2.5 Asignar espacio con malloc
		* 2.6 Guardar cadena hasta dicho limitador
		* 2.7 Liberar memoria
		* 2.8 Volver a empezar el bucle
		! Mejor contar las cadenas y mientras se repita el delimitardor
			! mover el puntero
		! Si existe el puntero y no es igual al delimitador calcular el len
			! hasta el siguiente limitador
		! Manejar los errores de asignación de memoria
		!Terminar las strings correctamente con \0
		!Mover el puntero todas las posiciones copiadas al array de strings
		!Finalizar el array de strings con NULL para que se reconozca

	X. Null si falla la reserva de memoria use malloc y free
 */
#include "libft.h"

static	int	ft_delimits(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static int	ft_free_strs(char **strs, size_t j)
{
	while (j > 0)
	{
		j--;
		free(strs[j]);
	}
	free(strs);
	return (0);
}

static	int	ft_do_split(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	h;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		strs[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!strs[j])
			return (ft_free_strs(strs, j));
		h = 0;
		while (h < i)
			strs[j][h++] = *s++;
		strs[j++][h] = '\0';
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_delimits(s, c) + 1));
	if (!strs)
		return (NULL);
	if (!ft_do_split(strs, s, c))
		return (NULL);
	return (strs);
}
