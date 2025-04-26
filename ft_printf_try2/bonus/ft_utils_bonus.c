#include "../ft_printf.h"

int ft_justify_left(char **menu, va_list args)
{
	int move;
	char	c;
	int	i;
	int	size;

	size = 0;
	(*menu)++;
	ft_space(menu, args);
	move = ft_atoi(*menu);
	while (ft_isdigit(**menu))
		(*menu)++;
	i = 0;
	if (**menu == ' ')
	{
		ft_space(menu, args);
		size += ft_printstr("% -");
		size += ft_printf("%d ", move);
		size += ft_printchar(**menu);
	}else
	{
		size += ft_base(menu, args);
		while (i < move - 1)
			i += ft_printchar(' ');
	}
	return (size + i);
}
int ft_equals_cero(char **menu, va_list copy)
{
	if (**menu)
		copy = copy;
}
int ft_point(char **menu, va_list copy)
{
	if (**menu)
		copy = copy;
}
int ft_pound(char **menu, va_list copy)
{
	if (**menu)
		copy = copy;
}
int ft_plus(char **menu, va_list copy)
{
	if (**menu)
		copy = copy;
}
void ft_space(char **menu, va_list args)
{
	while (**menu == ' ' && **menu != '\0')
		(*menu)++;
}