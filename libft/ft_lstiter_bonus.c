/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:32:45 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/16 19:57:15 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* 
	lst es un puntero al primer nodo que se apunta que lueo podremos iterar
	f es la funcion que utilizamos para cada nodo
	TODO no retorna nada
	! Nada autorizado
	Avanza por la lista y aplica "f" en el contenido de cada nodo
		1. Recorrer la lista con lst dado que es un ptemporal
		2.Aplicar f a su valor
		3. Detener el bucle cuando sea igual a NULL
		4. No hacer nada y vivir otro día más
 */