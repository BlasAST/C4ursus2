/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:26 by marvin            #+#    #+#             */
/*   Updated: 2025/11/18 01:07:53 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argn, char **args)
{
	t_data	*dt;

	if (argn != 2)
		error_ex("2 params: ./fdf file.fdf\n", 1);
	check_validate_file_and_save(args[1]);
	dt = (t_data *)malloc(sizeof(t_data));
	if (!dt)
		error_ex("Error create data", 1);
	create_ini(dt, args[1]);
	put_sizes_fdf(dt);
	functions_win(dt);
	// events();
	// ft_printf("%s", dt->file);
	// paint(dt, 0xFFFFFF);
	finish_fdf(dt);
	frees_t_data(dt, 0);
	return (0);
}
