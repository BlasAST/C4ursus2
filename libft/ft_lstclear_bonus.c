/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:44:41 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/16 20:41:19 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

/* 
	lst direcciond e un puntero a un nodo
	del un puntero a la funcion para eliminar el contenido del lodo
	TODO Elimina y libera el nodo y todos los consecutivos a dicho nodo
	TODO usando del. Al final el puntero a la lista debe de ser null
		
		recorrer la lista desde el puntero que nos pasan
		e ir borrando todos los elementos de la lista
		actualizando temp y que temp vaya apuntando al siguiente una vez se
		borra el actual hasta que sea null
		Hay que buscar una forma de que la primera vez el puntero
		 pase a ser null para que 
		a todo lo demás de la lista no le afecte
 */