/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:06:03 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/17 01:39:22 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ! Funciones adicionales para realizar parseo de cosas varias

void	ft_lstiter_fdf(t_list *lst, void (*f)(void *content, void *context),
void *context)
{
	while (lst != NULL)
	{
		f(lst->content, context);
		lst = lst->next;
	}
}

void	save_points()
{
	
}