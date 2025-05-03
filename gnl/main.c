#include "get_next_line.h"


int main(void)
{
	// int value = open("el_quijote.txt", O_RDONLY);
	int value = open("nose.txt", O_RDONLY);
	char *c;
	while ((c = get_next_line(value)))
	{
		ft_print_buffer(c);
	}

	/* ft_print_buffer(get_next_line(value));
	ft_print_buffer(get_next_line(value));
	ft_print_buffer(get_next_line(value)); */
}


// Asignar espacio a buffer
// Leer con el buffer
// Si el buffer a encontrado el final trabajar el ultimo buffer
// Asignar espacio a last_buffer y copiar buffer
// Buscar  \N
		// Si no se encuentra repetir
		// realizar otra lectura para repetir
	// Si la lectura encuentra el final trabajar el ultimo buffer DEVOLVERLO A RETURN BUFFER
	// Si se detiene por el bucle devolver todo lo del buffer statico hasta el  \n
	// Se desplaza la static hasta el siguiente sin el  \n
	// Que pasa con el \n si se llama en la siguiente iteración?
	// retornar return buffer