/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:35:20 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/11 13:54:30 by bsiguenc         ###   ########.fr       */
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
#endif