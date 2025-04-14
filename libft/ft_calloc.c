/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:03:57 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/14 12:04:02 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t i;
	void *pointer;

	if (nmemb > 0 && size > 0)
	{
		pointer = malloc (nmemb * size);
		if (!pointer)
			return (NULL);
		i = 0;
		while (i < nmemb * size)
		{
			((char *)pointer)[i] = '\0';
			i++;
		}
		return (pointer);
	}
	return (NULL);
}