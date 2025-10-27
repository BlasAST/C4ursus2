/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:24:23 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/22 13:16:39 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < '0' || str[i] > '9') \
			&& str[i] != '+' && str[i] != '-')
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
	if (!reconv)
		return (1);
	if (arg[0] == '+')
		arg++;
	if (ft_strncmp(reconv, arg, ft_strlen(reconv)) != 0)
	{
		free(reconv);
		return (1);
	}
	free(reconv);
	return (0);
}

int	check_atoi(char *arg)
{
	int		number;
	char	*reconv;

	number = ft_atoi(arg);
	reconv = ft_itoa(number);
	if (ft_strncmp(reconv, arg, ft_strlen(arg)) != 0)
	{
		free(reconv);
		return (1);
	}
	free(reconv);
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
	if (arg[i] != ' ' && arg[i] != '\0')
		return (-1);
	return (i);
}
