#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct swap_node
{
    int value;
    int index;
    struct swap_node *next;
} swap_node;
swap_node	*create_node();
void	show_nodes(swap_node **node, char *str_print);
void	push(swap_node **from, swap_node **to, char *str_print);
void	swap(swap_node	**node, char *str_print);
void	rotate(swap_node **node, char *str_print);
void	reverse_rotate(swap_node **node, char *str_print);
int	add_values(swap_node **node, int len, char **args);
int	check_args(char *args, swap_node **node);

#endif