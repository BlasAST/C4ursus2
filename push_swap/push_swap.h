/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:21:32 by marvin            #+#    #+#             */
/*   Updated: 2025/06/27 14:26:25 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int	    *ft_putargs(int argn, char **args);
void	ft_print_arr(int  *arr, int len);
int	    ft_len_arr(int *arr);
void	swap_a(int *arr);
void	swap_b(int *arr);
void	swap_ab(int *arr_a, int *arr_b);
void	push_a(int *arr_a, int *arr_b, int len);
void	push_b(int *arr_b, int *arr_a, int len);
void	rotate_a(int *arr_a, int len);
void	rotate_b(int *arr_a, int len);
void	rotate_ab(int *arr_a, int *arr_b);
void	reverse_rotate_a(int *arr_a, int len);
void	reverse_rotate_b(int *arr_b, int len);
void	reverse_rotate_ab(int *arr_a, int *arr_b,  int len);
int	    ft_filter_swap(int	*a, int len);
int	    ft_find_smaller(int *arr, int smaller);
#endif