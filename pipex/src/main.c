#include "pipex.h"

void pipex(char *file1, char *cmd1, char *cmd2, char *file2)
{
    int fd;
    char *message;

    ft_printf("file 1: %s, file 2: %s, cmd1: %s, cmd2: %s", file1, file2, cmd1, cmd2);
    fd = check_file(file1, &message);
    ft_printf("%s", message);
    close(fd);
}

int main(int argn, char **args)
{
    if (argn != 5)
        return (0);
    pipex(args[1], args[2], args[3], args[4]);
    return (0);
}

// Rutas donde busca el shell:
// /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
