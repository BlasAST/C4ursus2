/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/03 17:29:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

typedef struct t_img
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
} t_img_data;

typedef struct t_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	struct t_img i_d;
	int		map_size_w;
	int		map_size_h;
	int		**map_z_values;
	int		zoom;
	int		offset_x;
	int		offset_y;
} t_data;

typedef struct t_point
{
	int	x;
	int	y;
	int	z;
} t_point;

void    create_ini(t_data *df);
void    finish_fdf(t_data *df);

#endif