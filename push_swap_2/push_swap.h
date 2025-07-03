#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct swap_node
{
    int value;
    int index;
    struct swap_node *next;
} swap_node;
void	show_nodes(swap_node **node, char *str_print);
void	push(swap_node **from, swap_node **to);
#endif