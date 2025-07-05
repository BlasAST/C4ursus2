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
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] <= '0' || str[i] >= '9')
			&& str[i] != '+' && str[i] != '-')
			return (1);
		i++;
	}
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

/* int	check_digits(char *args)
{
	int	i;
	int	simbol;

	i = 0;
	simbol = 0;
	while (args[i] == ' ' || (args[i] >= 9 && args[i <= 13]))
		i++;
	if (args[i] == '+' || args[i] == '-')
	{
		if (args[i] == '-')
			simbol = -1;
	}
	while (args[i] >= '0' && args[i] <= '9' || args[i] == ' ')
	{
		i++;
	}
} */

void	ft_conver_digits(char *args, swap_node **node)
{
	int	i;
	int	val;

	i = 0;
	while (args[i])
	{
		while (args[i] && args[i] == ' ')
			i++;
		val = ft_atoi(&args[i]);
		if ((args[i] == '+' || args[i] == '-') && args[i + 1] != ' '
		|| args[i + 1] != '\0')
			i++;
		while (args[i] && args[i] >= '0' && args[i] < '9')
			i++;
		(*node)->index = 110;
		(*node)->value = val;
		if (args[i] != '\0')
		{
			(*node)->next = create_node();
			(*node) = (*node)->next;
		}
		i++;
	}
}

int	check_args(char *args, swap_node **node)
{
	int	i;

	if (check_atoi(args) == 1)
	{
		if (ft_valid_string(args) == 1)
			return (1);
		else
			ft_conver_digits(args, node);
	}
	else
		(*node)->value = ft_atoi(args);
	return (0);
}
