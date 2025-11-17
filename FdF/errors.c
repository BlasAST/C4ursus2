/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:07:42 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/17 00:45:40 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ! Fichero para el manejo de errores. Mirar a ver que otros
// ! errores se deben de manejar aqui
void	error_ex(char *str, int error)
{
	write(2, str, ft_strlen(str));
	exit(error);
}
