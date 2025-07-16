/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisber <aisber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:45:58 by aisber            #+#    #+#             */
/*   Updated: 2025/07/16 02:40:13 by aisber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_print_bits(unsigned int octet)
{
    if (octet > 1)
        ft_print_bits(octet / 2);
    printf("%d", octet % 2);
}

void print_bits(unsigned char rest)
{
    int i = 8;
    unsigned char bit = 0;

    while (i--)
    {
        bit = (rest >> i & 1) + '0';
        printf("%c", bit);
    }
}

int main(void)
{
    // unsigned int nb = 88;
    // ft_print_bits(nb);
    // printf("nb\n");
    print_bits(9);
    // printf("nb\n");
    
}