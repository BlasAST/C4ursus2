#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // necesario para open() y type de open;
#include <errno.h> //necesario para access() y strerror()
#include <string.h> //necesario para strerror()


int main(void)
{
    int fd;
    char buffer[100];
    char *error;
    ssize_t bytes;
    fd = open("text.txt", O_WRONLY);
    // Manejo de error en caso de fallar en la apertura del fichero
    if (fd == -1)
    {
        if (errno != EACCES)
        {
            printf("Permisos permitidos por acceso");
        }
        else
        {
            error = strerror(errno);
            printf("%s", error);
        }
        // Uso de perror
        // perror("Error en la apertura del archivo");
        return (1);
    }
    /* En el printd hay un error porque printf envia el contenido a su destino final cuando encuentra un \n
    y al encontrarlo lo manda por trozos y el programa sigue mientras tanto */
    printf("El descriptor de archivo es: %d\n y esto no esta en el archivo hasta que \
        se cambie la salida estandar", fd);
    dup2(fd, STDOUT_FILENO);
    printf("Ahora esta esto en el archivo\n\n");
    close(fd);
    /* bytes = read(fd, buffer, sizeof(buffer) - 1);
    while(bytes > 0)
    {
        buffer[bytes] = '\0';
        printf("%s", buffer);
        bytes = read(fd, buffer, sizeof(buffer) - 1);
    }
    close(fd); */
    return (0);
}