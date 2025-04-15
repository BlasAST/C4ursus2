/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:06:57 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 18:12:33 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	i;

	temp = lst;
	i = 0;
	if (!temp)
		return (0);
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/* 
	obtener la longitud de la lista
	Contar el numero de nodos
		1.Variable int
		2.Recorrer la lista con puntero temporal
			para no modificar el puntero original
			de la lista
		3.Mover el puntero temporal al siguiente
		4.Comprobar que no sea igual a null
		5.MIentras no sea igual a NULL
		6.return size;
*/