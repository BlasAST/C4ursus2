/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:56 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/10 13:57:23 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		*(unsigned char *) s = (unsigned char) c;
		i++;
		s++;
	}
}
/*Si funciona como se dice n seria un size_t*/