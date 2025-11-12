/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:04:01 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/12 13:00:07 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(char **command, char **routes, char *route_temp)
{
	free_split(command);
	free_split(routes);
	free(route_temp);
}

void	error_ex(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
