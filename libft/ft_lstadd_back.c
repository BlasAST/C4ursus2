/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:16:25 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 19:29:58 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		new = ft_lstnew(NULL);
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

/*
	lst es el puntero al primer nodo de la lista
	new es el nodo a añadir
	TODO no devuelve nada
	Añade el nodo new al final de "lst"
		1.Crear temporal dado que voy a modificar lst
		2.Comprobar si el principio no es igual a null
			si lo es new es el inicio
			si no
		3.Recorrer hasta encontrar el next null
		4. Asignar el new donde estaba el null
			y establecer al new next el null
	!MANEJAR ERRORES DE SEGMENTACIÓN
*/