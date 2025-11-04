/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:30:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/04 13:11:38 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int key_code)
{
	if (key_code == 65307)
		exit(0);
	return (0);
}

static int	close_button()
{
	exit(0);
}

void	functions_win(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_button, data);
}
