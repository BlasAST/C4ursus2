
#include "ft_printf.h"

int ft_print_other_value(char **c)
{
	if (**c == '%')
	{
		if (**c == '%' && (*(*c + 1) == '%' || *(*c + 1) == ' '))
			ft_printchar('%');
		else
			ft_printchar('%');
	}
	else if (**c == ' ')
	{
		while (**c == ' ')
			(*c)++;
		if (**c != '%')
		{
			ft_printstr("% ");
			ft_printchar(**c);
		}
		else
			ft_printchar('%');
	}
	else
	{
		ft_printchar('%');
		ft_printchar(**c);
	}
	return (2);
}
