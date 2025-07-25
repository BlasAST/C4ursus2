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
int	ft_find_min(swap_node **node);
int	ft_find_nex_min(swap_node **node, int min);
void	conditions_min_a(swap_node **a, swap_node **b, int min_a, int min_b);
void	conditions_min_b(swap_node **a, swap_node **b, int min_a, int min_b);
int	ft_nodes_in_order(swap_node **node);

#endif