/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:47:11 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/22 15:51:32 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(double nb)
{
	int	size;
	int	dec;

	size = 0;
	if (nb < 0)
	{
		ft_printchar('-');
		nb = -nb;
	}		
	size += ft_printeger((int) nb);
	nb -= (int) nb;
	if (nb == 0)
		return (size);
	ft_printchar('.');
	size++;
	dec = 0;
	while (dec < 6)
	{
		nb *= 10;
		ft_printchar((int) (nb + 0.5) + '0');
		nb -= (int) (nb + 0.5);
		dec++;
	}
	return (size + dec);
}
