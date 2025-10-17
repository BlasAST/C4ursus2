/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:03:45 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/10/07 13:17:31 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pid1(int *pid, int *fds, char *cmd1, char **envp)
{
	char	**command;

	dup2(fds[0], STDIN_FILENO);
	dup2(pid[1], STDOUT_FILENO);
	close(pid[0]);
	close(pid[1]);
	command = ft_split_pipex(cmd1, ' ');
	exec_command(command, envp);
	free(command);
}

void	do_pid2(int *pid, int *fds, char *cmd2, char **envp)
{
	char	**command;

	dup2(pid[0], STDIN_FILENO);
	dup2 (fds[1], STDOUT_FILENO);
	close (pid[0]);
	close (pid[1]);
	command = ft_split_pipex(cmd2, ' ');
	exec_command(command, envp);
	free(command);
}
