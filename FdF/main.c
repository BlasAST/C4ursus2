/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:26 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 17:39:02 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_fdf(char *str)
{
	char	*valid_extension;
	int		i;

	if (!str)
		return (1);
	valid_extension = ".fdf";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != valid_extension[i])
			return (1);
		i++;
	}
	if (valid_extension[i] != '\0')
		return (1);
	return (0);
}

char	*check_validate_file_and_save(char *str)
{
	char	*extension;

	extension = ft_strrchr(str, '.');
	if (!extension || check_file_fdf(extension) == 1)
		error_ex("Error file: The extension must be .fdf", 1);
	return (str);
} 

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
	dt->map_lines =  read_file(dt->file);
	ft_lstiter(dt->map_lines, print_content);
	functions_win(dt);
	// events();
	// ft_printf("%s", dt->file);
	// paint(dt, 0xFFFFFF);
	finish_fdf(dt);
	return (0);
}
