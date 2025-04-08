/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:38:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/08 17:16:39 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// Si funciona como dicen ft_strlen devuelve un size_t