/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:42:35 by blas              #+#    #+#             */
/*   Updated: 2025/11/18 01:26:21 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// * Funcines temporales que luego se pueden borrar
void	print_content(void *content)
{
	ft_printf("%s", (char *)content);
}
	// close(fd);