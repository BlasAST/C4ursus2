/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:01:26 by aisber            #+#    #+#             */
/*   Updated: 2025/04/19 19:40:33 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*new_nodo;
	t_list	*ini;
	void	*content;
	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_lst = ft_lstnew(content);
	if (!new_lst)
	{
		del(new_lst->content);
		free(new_lst);
	}
	ini = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = lst->next;
		content = f(lst->content);
		new_nodo = ft_lstnew(content);
		if (!new_nodo)
		{
			del(new_nodo->content);
			free(new_nodo);
		}
		new_lst->next = new_nodo;
		new_lst = new_nodo;
		lst = lst->next;
	}
	return (ini);
}

int	main(void)
{
	t_list	*lista = (t_list *)malloc(sizeof(t_list));
	lista->content = malloc(sizeof(char) * 12);
	lista->next = NULL;
	*(int *)lista->content = 234;
	printf("%d", *(int *)lista->content);
	return (0);
}

/*
	* Basicamente, hacer un map en el que a cada elemento le aplico una funcion
	* Si falla la asignación de memoria eliminar la lista
*/