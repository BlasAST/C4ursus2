/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:35:20 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/10/20 09:13:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct t_swap_node
{
	int					value;
	int					index;
	struct t_swap_node	*next;
}	t_swap_node;
t_swap_node	*create_node(void);
void		show_nodes(t_swap_node **node, char *str_print);
void		push(t_swap_node **from, t_swap_node **to, char *str_print);
void		swap(t_swap_node	**node, char *str_print);
void		rotate(t_swap_node **node, char *str_print);
void		reverse_rotate(t_swap_node **node, char *str_print);
int			add_values(t_swap_node **node, int len, char **args);
int			check_args(char *args, t_swap_node **node);
int			ft_find_min(t_swap_node **node);
int			ft_find_nex_min(t_swap_node **node, int min);
int			ft_nodes_in_order(t_swap_node **node);
void		add_index(t_swap_node **node);
int			size_nodes(t_swap_node *node);
int			check_valid_string(char *str);
int			check_range(char *arg);
int			check_atoi(char *arg);
int			check_number_conversion(char *arg);
int			find_index(t_swap_node *node, int max);
int			get_chunk_size(int size);
int			get_max_index(t_swap_node *node);
void		order_three(t_swap_node **a);
void		order_five(t_swap_node **a, t_swap_node **b);
void		order_max_order(t_swap_node **b, t_swap_node **a);
void		order_chunks(t_swap_node **a, t_swap_node **b, int size);
int			clean_nodes(t_swap_node **node);
#endif