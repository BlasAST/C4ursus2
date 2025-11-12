/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:43:14 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/12 13:17:11 by bsiguenc         ###   ########.fr       */
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

int	find_char(char *str, char t_char)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == t_char)
			return (1);
		i++;
	}
	return (0);
}

char	*try_routes(char *route, char *command)
{
	char	*temp_path;
	char	*temp;

	if (find_char(command, '/') == 1)
	{
		temp = ft_strdup(command);
		if (!temp)
			return (NULL);
		return (temp);
	}
	else
	{
		temp_path = ft_strjoin(route, "/");
		if (!temp_path)
			return (NULL);
		temp = ft_strjoin(temp_path, command);
		free (temp_path);
		return (temp);
	}
}
