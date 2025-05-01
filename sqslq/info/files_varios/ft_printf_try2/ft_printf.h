/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/26 19:57:59 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_base(char **menu, va_list args);
int	ft_printf(const char *str, ...);
int ft_selection_main(char **menu, va_list args);
int	ft_printchar(char c);
int	ft_printeger(int nb);
int	ft_printeger_unsig(unsigned int nb);
int	ft_printstr(char *c);
int	ft_print_hex(unsigned int nb, char c);
int	ft_print_address(unsigned long nb, int upper);

/* Bonus */
int ft_justify_left(char **menu, va_list copy);
int ft_equals_cero(char **menu, va_list copy);
int ft_point(char **menu, va_list copy);
int ft_pound(char **menu, va_list copy);
int ft_plus(char **menu, va_list copy);
void ft_space(char **menu, va_list copy);
#endif