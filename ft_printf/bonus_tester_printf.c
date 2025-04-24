/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tester_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:56:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/24 13:46:46 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
    char *str = "-Hola buenas tardes \n";
    int nb = -123;
	printf("%+k\n\n", nb);
    ft_printf("%d", str);
}