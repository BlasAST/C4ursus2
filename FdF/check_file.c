/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:40:05 by blas              #+#    #+#             */
/*   Updated: 2025/11/18 01:24:48 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ! Comprobación del fichero .fdf para ver si es valido

int	check_file_fdf(char *str)
{
	char	*valid_extension;
	int		i;

	if (!str)
		return (1);
	valid_extension = ".fdf";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != valid_extension[i])
			return (1);
		i++;
	}
	if (valid_extension[i] != '\0')
		return (1);
	return (0);
}

char	*check_validate_file_and_save(char *str)
{
	char	*extension;

	extension = ft_strrchr(str, '.');
	if (!extension || check_file_fdf(extension) == 1)
		error_ex("Error file: The extension must be .fdf", 1);
	return (str);
} 