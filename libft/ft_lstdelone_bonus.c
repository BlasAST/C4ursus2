/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:35:04 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 19:03:43 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* 
	lst es el nodo que se quiere eliminar
	del  es la funcion que maneja la liberación de memoria
	TODO se puede usar free
		Lo que hace es recibir un nodo y de ese nodo se 
		libera su contendo aunque el nodo sigue existiendo
 */