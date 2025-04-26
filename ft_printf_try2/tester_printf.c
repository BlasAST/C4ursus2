
#include "ft_printf.h"

void	spaces()
{
	int	i;

	i = 0;
	ft_printchar('\n');
	while (i < 20)
	{
		ft_printchar('-');
		i++;
	}
	ft_printchar('\n');
}

/* 
int main()
{
	printf("%        k   claro que si  Aqui comiendome un rico %d manguito", 22);
	spaces();
	ft_printf("%        k   claro que si  Aqui comiendome un rico %d manguito\n\n", 22);
		printf("\nTe juro por mi vida que %s me %%s%%s ja tocado %d los% % %  %%  -5 brazos %u no quiero nada más %c\n\n","el algorimto", 4, -6, 'A');
	ft_printf("\nTe juro por mi vida que %s me %%s%%s ja tocado %d los% % %  %%  -5 brazos %u no quiero nada más %c\n\n","el algorimto", 4, -6, 'A');
} */

/* int	main()
{
	ft_printf(" %c \n", '0');
	ft_printf("%p \n",  -1);
	printf("NULL %s NULL \n", NULL);
	ft_printf("NULL %s NULL \n", NULL);
	
	printf("%p %p", 0, 0);
	ft_printf("%p %p", 0, 0);
} */

int main(void)
{
	char *str = "Las, como estas?";
	char c = 'o';
	// int	n = - - +  - 12;
	int	n = 12;
	int h = - 123;
	int hex = - 12;
	/* 
		* Tester de  align left
	printf("\nPrintf: \n %-21d holaaaaaaaaaaaaaaaa\n %- 11d holaaaaaaaaaaaaaaaa\n % - 5 d holaaaaaaaaaaaaaaaa\n % -5 d holaaaaaaaaaaaaaaaa\n", n, n, n, n);
	ft_printf("\nft_Printf: \n %-21d holaaaaaaaaaaaaaaaa\n %- 11d holaaaaaaaaaaaaaaaa\n % - 5 d holaaaaaaaaaaaaaaaa\n % -5 d holaaaaaaaaaaaaaaaa\n", n, n, n, n);
	 */

	
	// printf("Printf: \n %-10d hola \n %010d \n %.3d \n %#x %+d\n\n", n, n, n, n, n);
	// ft_printf("Ft_printf: \n %-10d hola \n %010d \n %.3d \n %#x %+d\n\n", n, n, n, n, n);
/* 	
		* Tester general de printf
	spaces();
	ft_printf("\nTester ft_printf:\n Enteros: %d \t\t Enteros: %i \n Enteros sin signo: %u \
		\t\t Strings: %s \t\t Caracteres: %c \t\t \nHexadecimales: \n\t\t \tLower: %x \
		\t\t \tUpper: %X \t\t \n\n Porcentaje: %%\t\t Puntero: %p\t\t \n\n\nOtras pruebas: \
		\n %^'a %k %N %%% %:% %%%d %\n\n \
		%% 0 %% d %%%d % 4 % 668 %     %% 8    h      o     % \n\n",
		n, n, h, str, c, hex, hex, &str);
	spaces();
	spaces();
	printf("\nTester printf:\n Enteros: %d \t\t Enteros: %i \n Enteros sin signo: %u \
		\t\t Strings: %s \t\t Caracteres: %c \t\t \nHexadecimales: \n\t\t \tLower: %x \
		\t\t \tUpper: %X \t\t \n\n Porcentaje: %%\t\t Puntero: %p\t\t \n\n\nOtras pruebas: \
		\n %^'a %k %N %%% %:% %%%d %\n\n \
		%% 0 %% d %%%d % 4 % 668 %     %% 8    h      o     % \n\n",
		n, n, h, str, c, hex, hex, &str);
	spaces();

	spaces();
	printf("Te juro por mi vida que %s me %%s%%s ja tocado %d los% % %  %%  -5 brazos %u no quiero nada más %c\n\n","el algorimto", 4, -6, 'A');
	ft_printf("Te juro por mi vida que %s me %%s%%s ja tocado %d los% % %  %%  -5 brazos %u no quiero nada más %c\n\n","el algorimto", 4, -6, 'A');
 */

}

/*
Cosas a tener en cuenta:
A parte de que printf debe de devolver la longitud correctamente
Tambien si le pasan null a string debe devolver (null)
Y si se le pasan 0  a un %p debe devolver (nil)
El manejo de los % es raro, mirar a ver que tal.
*/