/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:21:32 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/24 13:47:01 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_plus(char **c, va_list args)
{
	int	nb;
	int	size;

	nb = va_arg(args, int);
	size = 0;
	if (nb)
	{
		if (nb >= 0)
		{
			size += ft_printchar('+');
			size += ft_printeger(nb);
		}
	}
	else
	{
		size += ft_printchar('+');
		(*c)++;
		
	}
	return (size);
}

int	ft_bonus_printf(char **c, va_list args)
{
	int	i;

	i = 0;
	if (**c == '+')
		ft_plus(c, args);
	**c = **c;
	return (0);
}

