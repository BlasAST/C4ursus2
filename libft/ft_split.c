/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:49:12 by blas              #+#    #+#             */
/*   Updated: 2025/04/15 01:53:41 by blas             ###   ########.fr       */
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
	size_t i;

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

static	int	ft_len_delimit(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void ft_free_strs(char **strs)
{
	size_t i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static	void ft_add_str(char const *s, char c)
{}

char	**ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t len;
	char **strs;
	
	i = 0;
	strs = (char **)malloc(sizeof(char *) * (ft_delimits(s,c) + 1));
	if (!strs || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_len_delimit(s,c);	
			strs[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!strs[i])
			{
				ft_free_strs(strs);
				return (NULL);
			}
			j = 0;
			while (s[j] && s[j] != c)
			{
					strs[i][j] = s[j];
					j++;
			}
			strs[i][j] = '\0';
			s+= len;
			i++;
		}
	}
	strs[i] = NULL;
	return (strs);
}