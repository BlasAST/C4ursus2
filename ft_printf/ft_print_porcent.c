#include "ft_printf.h"

int ft_print_porcent(char **str)
{
	(*str)++;
	while (**str == '%' || **str == ' ')
	{
		if (**str == '%')
			ft_printchar('%');
		(*str)++;
	}
	
	ft_printchar(**str);
	return (1);
}