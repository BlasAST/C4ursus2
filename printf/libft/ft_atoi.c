/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:04:15 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:38:41 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	neg;

	number = 0;
	neg = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr ++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + *nptr - '0';
		nptr++;
	}
	if (neg)
		number *= -1;
	return (number);
}

/*
int main(void)
{
	char *a = "\n   -l12341a611";
	printf("%d\n\n", atoi(a));
	printf("%d", ft_atoi(a));
} */