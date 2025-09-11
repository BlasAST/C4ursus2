/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:24:23 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/11 14:01:22 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' && str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_range(char *arg)
{
	int		number;
	char	*reconv;

	number = ft_atoi(arg);
	reconv = ft_itoa(number);
	if (arg[0] == '+')
		arg++;
	if (ft_strncmp(reconv, arg, ft_strlen(reconv)) != 0)
		return (1);
	return (0);
}

int	check_atoi(char *arg)
{
	int		number;
	char	*reconv;

	number = ft_atoi(arg);
	reconv = ft_itoa(number);
	if (ft_strncmp(reconv, arg, ft_strlen(arg)) != 0)
		return (1);
	return (0);
}

int	check_number_conversion(char *arg)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (arg[i] < '0' || arg[i] > '9')
		return (-1);
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	return (i);
}
