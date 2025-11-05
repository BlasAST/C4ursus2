/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/05 16:59:37 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

typedef struct t_img
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct t_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct t_img	i_d;
	int				map_size_w;
	int				map_size_h;
	int				**map_z_values;
	int				zoom;
	int				offset_x;
	int				offset_y;
	struct t_list	*map_lines;
}	t_data;

typedef struct t_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

/* typedef struct file_ln
{
	char *line;
	struct file_ln *next;
}	file_ln; */

/* Inicio */
void	create_ini(t_data *df);

// Manejo de eventos y ventana
void	functions_win(t_data *data);
void	events(void);

// Lectura de fichero
int		open_file(char *str);
char	**read_file(char *str);

/* REsize de imagen */
// void    clear_image(t_data *data, int color);

// Pintar en imagen
void	paint(t_data *data, int color);
void	put_pixel(t_img_data *img, int x, int y, int color);
void	draw(char *file);

// Funciones crear y pintar rgb
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// Manejo de errores
void	error_ex(char *str);

/* Loop y final programa */
int		clean_and_exit(t_data *data);
void	finish_fdf(t_data *df);
#endif