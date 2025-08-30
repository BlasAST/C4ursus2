#include "pipex.h"

int check_file(char *file, char **message, int param)
{
	int fd;

	if (param == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			if (errno == ENOENT)
				*message = ft_strjoin("Archivo no encontrado: ", file);
			else if (errno == EACCES)
				*message = ft_strjoin("Sin permisos de lectura: ", file);
			else
				*message = ft_strjoin("Error al abrir archivo: ", file);
		}
	}
	else
	{
		fd = open(file, O_WRONLY |O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			*message = ft_strjoin("Error al crear/abrir archivo de salida: ", file);
	}
	return (fd);
}