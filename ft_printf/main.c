/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/22 15:00:25 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char *str = "Las, como estas?";
	int	n = - - +  - 12;
	double db = 1123412342.11;/* 
	ft_printf("como tu%s %c te ll %d ama %%h yo no\n\n", "Hola que tal estas" ,"aaa", 12345);
	
	printf ("HOla, si %s %%d %c %p %% %c %h %d %i %u %x %X",
	"soy yo", 'B', str, 'C', db , 30, 123, 123 , 1234); */
	/* Enteros */
	ft_printf("%d\n", db);
	printf ("%f", db);
	/* Caracteres */
	
}