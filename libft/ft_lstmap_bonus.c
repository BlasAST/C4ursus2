/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:23:33 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/16 21:33:52 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	do_map(t_list *lst, void *(*f)(void *),
t_list **n, void (*del)(void *))
{
	t_list	*new_nodo;
	void	*data;

	data = f(lst->content);
	new_nodo = ft_lstnew(data);
	if (!new_nodo)
	{
		del(data);
		return (0);
	}
	(*n)->next = new_nodo;
	*n = new_nodo;
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ini;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	data = f(lst->content);
	new_lst = ft_lstnew(data);
	if (!new_lst)
	{
		del(data);
		return (NULL);
	}
	ini = new_lst;
	lst = lst->next;
	while (lst)
	{
		if (!do_map(lst, f, &new_lst, del))
		{
			ft_lstclear(&ini, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (ini);
}

/* 
	Recorre lst y aplica f
	Crea una lista resultante del resultado de f
	la funcion del se usa para eliminar el contenido de un nodo
	si es que hace falta

	while
		1.Temp es igual al siguiente
		el contenido del nuevo es el contenido del lst
		eliminto el  el contenid de lst
		libero lst
		la nueva lista es igual a next
		el actual es igual al temp que guardamos al principio
 */