/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/17 01:48:46 by blas             ###   ########.fr       */
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
	char			*file;
	void			*mlx_ptr;
	void			*win_ptr;
	struct t_img	i_d;
	int				map_size_w;
	int				map_size_h;
	int				**map_z_values;
	int				zoom;
	int				offset_x;
	int				offset_y;
	t_list			*map_lines;
}	t_data;

typedef struct t_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

/* typedef struct node_map
{
	int	line;
	int	pos;
	int	z;
	int	color;
	struct node_map *next;
}	node_map; */

/* typedef struct file_ln
{
	char *line;
	struct file_ln *next;
}	file_ln; */

/* // ! Inicio */
void	create_ini(t_data *df, char *file);

//*  Manejo de eventos y ventana
void	functions_win(t_data *data);
void	events(void);

// *Lectura de fichero y comprobaciones
int		check_file_fdf(char *str);
char	*check_validate_file_and_save(char *str);
void	check_lines_width(t_data *dt);
int		open_file(char *str);
t_list	*read_file(char *str);

// * Funciones guardado matriz
void	put_sizes_fdf(t_data *dt);
void	ft_lstiter_fdf(t_list *lst, void (*f)(void *content, void *context),
void *context);

/* // *REsize de imagen */
// void    clear_image(t_data *data, int color);

// Pintar en imagen
void	paint(t_data *data, int color);
void	put_pixel(t_img_data *img, int x, int y, int color);
void	draw(char *file, t_list **node);
int		points_paint(char *str);

// * Funciones crear y pintar rgb
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// *Manejo de errores
void	error_ex(char *str, int error);
void    free_split(char **arr);

/* //*Loop y final programa */
int		clean_and_exit(t_data *data);
void	finish_fdf(t_data *df);

/* //* FUnciones temporales: */
void	print_content(void *content);
#endif