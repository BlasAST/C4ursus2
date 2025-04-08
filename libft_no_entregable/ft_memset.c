/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:56 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/08 17:02:39 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_memset(void *s, int c, unsigned int n)
{
	int	i;

	i = 0;
	while (*(char *) s != '\0' && i != n)
	{
		*(char *) s = c;
		i++;
		s++;
	}
}
/*Si funciona como se dice n seria un size_t*/