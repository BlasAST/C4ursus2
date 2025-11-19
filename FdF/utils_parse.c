/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:06:03 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/18 23:54:35 by blas             ###   ########.fr       */
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

int	ft_find_fdf(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	save_points()
{
	
}