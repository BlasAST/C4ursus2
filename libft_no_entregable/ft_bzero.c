/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:27:25 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/08 15:52:06 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	int h;

	i = 0;
	h = ft_strlen((char *)s);
	while (i < n && i <= h)
	{
		((char *) s)[i] = '\0';
		i++;
	}
}