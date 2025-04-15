/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:04:51 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:39:56 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*reply;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	reply = (char *) ft_calloc(len + 1, sizeof(char));
	if (!reply)
		return (NULL);
	while (s[i] != '\0')
	{
		reply[i] = s[i];
		i++;
	}
	return (reply);
}

/*
int main(void)
{
	char *a = "hola buenas tardes";
	char *b = ft_strdup((const char *)a);
	printf ("%p ---- %p \n %s", a, b, b);
	free(b);
	return (0);
}
*/
