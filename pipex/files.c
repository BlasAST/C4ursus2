/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:43:14 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/03 13:36:38 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(char *file, int param)
{
	int	fd;

	if (param == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			if (errno == ENOENT)
				perror("Archivo no encontrado: ");
			else if (errno == EACCES)
				perror("Sin permisos de lectura: ");
			else if (errno == ENOEXEC)
				perror("Error al abrir archivo: ");
		}
	}
	else
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			perror("Error al crear/abrir archivo de salida: ");
	}
	return (fd);
}
