/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:10:45 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/14 13:41:52 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	end_program(char **routes, char **command, char **cmds)
{
	free_split(routes);
	write(2, command[0], ft_strlen(command[0]));
	write (2, ": command not found\n", 20);
	free_split(cmds);
	free_split(command);
	exit(127);
}

void	frees_errors_routes(char **routes, char **command, char **cmds)
{
	free_split(cmds);
	free_split(command);
	free_split(routes);
}

void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

void	close_pids(int *pids)
{
	close(pids[0]);
	close(pids[1]);
}
