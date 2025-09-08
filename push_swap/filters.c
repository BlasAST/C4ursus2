/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:09:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/08 13:25:40 by bsiguenc         ###   ########.fr       */
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
	int	number;
	char *reconv;

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
	int	number;
	char *reconv;

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
	if (arg[i] < '0' || arg[i]  > '9')
		return (-1);
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	return (i);
}

int	ft_conver_digits(char *args, swap_node **node)
{
	int	i;
	int	pos;

	i = 0;
	while (args[i])
	{
		while (args[i] == ' ')
			i++;
		pos = check_number_conversion(&args[i]);
		if (pos == -1 || check_range(&args[i]) == 1)
			return (1);
		else
		{
			(*node)->value = ft_atoi(&args[i]);
			i += pos;
			while (args[i] == ' ')
				i++;
			if (args[i] == '\0')
				return (0);
			else
			{
				(*node)->next = create_node();
				(*node) = (*node)->next;
			}
		}
		if (args[i] != '\0')
			i--;
		i++;
	}
	return (0);
}

int	check_args(char *args, swap_node **node)
{
	int	i;
	if (args[0] == '\0')
		return (1);
	if (check_atoi(args) == 1)
	{
		if (check_valid_string(args) == 1)
			return (1);
		else
		{
			if (ft_conver_digits(args, node) == 1)
				return (1);
		}
	}
	else
		(*node)->value = ft_atoi(args);
	return (0);
}
