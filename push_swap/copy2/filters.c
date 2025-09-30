/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:09:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/12 14:43:41 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid_string(t_swap_node **node, char *args, int *i, int pos)
{
	(*node)->value = ft_atoi(&args[*i]);
	*i += pos;
	while (args[*i] == ' ')
		(*i)++;
	if (args[*i] != '\0')
	{
		(*node)->next = create_node();
		(*node) = (*node)->next;
	}
}

int	ft_conver_digits(char *args, t_swap_node **node)
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
			valid_string(node, args, &i, pos);
		if (args[i] != '\0')
			i--;
		else
			return (0);
		i++;
	}
	return (0);
}

int	check_args(char *args, t_swap_node **node)
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
