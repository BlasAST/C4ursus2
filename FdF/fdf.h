/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/19 00:56:19 by blas             ###   ########.fr       */
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
	void	*img;//utilizado
	char	*addr;//utilizado
	int		bit_per_pixel;//utilizado
	int		line_length;//utilizado
	int		endian;//utilizado
}	t_img;

typedef struct t_point
{
	int	z;
	int	color;
}	t_point;

typedef struct t_data
{
	char			*file;//utilizado
	void			*mlx_ptr;//utilizado
	void			*win_ptr;//utilizado
	struct t_img	i_d;//utilizado
	int				map_size_w;//utilizado
	int				map_size_h;//utilizado
	int				map_size_w_view;
	int				map_size_h_view;
	int				zoom;
	int				offset_x;
	int				offset_y;
	t_list			*map_lines;//utilizado
	t_point			**map;
}	t_data;


/* // ! Inicio */
void	create_ini(t_data *df);

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
void	put_sizes_fdf(t_data *dt, char *file);
void	ft_lstiter_fdf(t_list *lst, void (*f)(void *content, void *context),
void *context);

// Funciones generación matriz
void	do_matrix(t_data *dt);
int	ft_find_fdf(char *str, char c);
int	ft_atoi_base(char *str, char *base);
/* // *REsize de imagen */
// void    clear_image(t_data *data, int color);

// Pintar en imagen
void	paint(t_data *data, int color);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw(char *file, t_list **node);
int		points_paint(char *str);
int	points_paint_split(char **str);

// * Funciones crear y pintar rgb
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// *Manejo de errores
void	error_ex(char *str, int error);
void    free_split(char **arr);
void	free_map(t_point **map, int height);
void	free_partial_map_and_exit(t_data *dt, int y);
void    frees_t_data(t_data *dt);

/* //*Loop y final programa */
int	clean_and_exit(t_data *data, int code, int exit_print, char *err);
void	finish_fdf(t_data *df);

/* //* FUnciones temporales: */
void	print_content(void *content);
void	print_matrix(t_data *dt);
#endif