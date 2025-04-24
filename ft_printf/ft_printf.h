/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/23 21:21:23 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printeger(int nb);
int	ft_printeger_unsig(unsigned int nb);
int	ft_printstr(char *c);
int	ft_print_hex(unsigned int nb, int upper);
int	ft_print_address(unsigned long nb, int upper);
int ft_print_porcent(char **str);
int ft_print_other_value(char **c);
#endif