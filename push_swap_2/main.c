/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/03 14:52:11 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argn, char **args)
{
    swap_node *a;
    swap_node *b;
    a = (swap_node *)malloc(sizeof(swap_node));
    a->value = 128;
    a->index = 1;
    b = (swap_node *)malloc(sizeof(swap_node));
    b->value = 123123;
    b->index = 2;
    swap_node *c;
    swap_node *d;
    c = (swap_node *)malloc(sizeof(swap_node));
    c->value = 919128;
    c->index = 3;
    d = (swap_node *)malloc(sizeof(swap_node));
    d->value = 6212362;
    d->index = 4;
    push(&b,&a);
    push(&c,&a);
    push(&d,&a);
    show_nodes(&a, "HOla");
}