/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/07/03 15:22:21 by bsiguenc         ###   ########.fr       */
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
    a->next = NULL;
    push(&b,&a, "Hola");
    push(&c,&a, "Hola");
    push(&d,&a, "Hola");
    show_nodes(&a, "HOla");
    swap(&a, "\n");
    show_nodes(&a, "HOla");
    rotate(&a,"\n");
    show_nodes(&a, "HOla");
    reverse_rotate(&a,"\n");
    show_nodes(&a, "HOla");
}