/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:43:14 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/10/17 11:07:42 by marvin           ###   ########.fr       */
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

char	*new_str(char *str, int size)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i] && i < size)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
