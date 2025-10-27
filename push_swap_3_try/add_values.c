/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:56:36 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 10:43:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_values(char **args, t_swap_node **node)
{
	int	i;

	i = 1;
	while (args[i])
	{
		// ft_printf("%s\n", args[i]);
		check_arg(args[i]);
		i++;
	}
}