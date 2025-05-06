#include "tester_gnl.h"

int	test_read(char **str, char *test)
{

}

char	*tester_buffers(int fd, int fd2)
{
	char *buffer;
	char *buffer_test;
	int	i;
	int	bytes;
	int	bytes_tester;
	int	bol;

	i = 1000000;
	bol = 0;
	buffer = malloc (sizeof(char) * (i + 1));
	buffer_test = malloc (sizeof(char) * (i + 1));
	if (!buffer || !buffer_test)
		return (NULL);
	bytes = 1;
	bytes_tester = 1;
	while (bytes > 0 && bytes_tester > 0)
	{
		bytes = read(fd, buffer, i);
		bytes_tester = read(fd2, buffer, i);
		if (bytes <= 0 || bytes_tester <= 0)
		{
			if (bytes > 0 || bytes_tester > 0)	
				return ("\nError en la lectura del buffer\n");
			return ("\nLectura correcta\n");
		}
		buffer[bytes] = '\0';
		buffer_test[bytes_tester] = '\0';
		if (test_read(buffer, buffer_test) == -1)
			return ("Error en la lectura del archivo");
		i /= 10;

	}
}

void	tester_gnl(char **str, char *test, int s_b)
{

}

int main(void)
{
	int fd = open("el_quijote.txt", O_RDONLY);
	int fd_tester = open("el_quijote.txt", O_RDONLY);
	char *c;


}