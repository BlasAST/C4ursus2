/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:07:24 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/10 13:52:46 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	size_t	i;
	unsigned char *dest_t = (unsigned char *)dest;
	unsigned char *src_t = (unsigned char *)src;

	i = 0;
	if (dest_t > src_t)
	{
		while (n--)
		{
			dest_t[i] = src_t[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			dest_t[i] = src_t[i];
		
	}
	return (dest_t);

}