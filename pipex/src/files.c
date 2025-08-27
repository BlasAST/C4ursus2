#include "pipex.h"

int check_file(char *file, char **message)
{
    int fd;

    fd = -1;
    if (access(file, F_OK) == 0)
    {
        if (access(file, R_OK) == 0)
        {
            fd = open (file, O_RDONLY | O_WRONLY);
            if (fd == -1)
            {}
        }
        else
        {
            *message = ft_strdup("Sin permisos de lectura:" );
            *message = ft_strjoin(*message, file);
        }
    }
    else
        *message = ft_strdup("El archivo o directorio no se ha encontrado\n");
    return (fd);
}