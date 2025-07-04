/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:09:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/04 14:29:45 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_string(char *str)
{
		
}

int	check_string(char *arg)
{
	int	number;
	char *reconv;

	number = ft_atoi(arg);
	reconv = ft_itoa(number);
	if (ft_strncmp(reconv, arg, ft_strlen(arg)) != 0)
		return (1);
	return (0);
}
int	check_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (check_string(args[i]) == 1)
		{
			return 1;
		}
		i++;
	}
	return (0);
}