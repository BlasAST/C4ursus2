/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:12:46 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/16 15:04:45 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (lst);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

/* 
	Funcion que recibe el principio de la lista
	TODO devuelve el ultimo nodo de la lista
		1.Recorrer con temporal
		2.Modificar con temporal
		3.Si temporal next es igual a NULL
			Detener el bucle y retornar dicho puntero
	

 */