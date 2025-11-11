/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:16:26 by marvin            #+#    #+#             */
/*   Updated: 2025/11/10 16:27:19 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argn, char **args)
{
	t_data	*df;

	if (argn != 2)
		return (1);
	df = (t_data *)malloc(sizeof(t_data));
	if (!df)
		return (1);
	create_ini(df);
	functions_win(df);
	events();
	draw(args[1], &df->map_lines);
	paint(df, 0xFFFFFF);
	// ft_lstiter(df->map_lines, print_content);
	finish_fdf(df);
	return (0);
}
