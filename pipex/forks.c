/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:03:45 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/11 12:43:36 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pid1(int *pid, int *fds, char *cmd1, char **envp)
{
	char	**command;

	if (dup2(fds[0], STDIN_FILENO) == -1 || dup2(pid[1], STDOUT_FILENO) == -1)
		exit(1);
	close(pid[0]);
	close(pid[1]);
	close(fds[0]);
	close(fds[1]);
	command = ft_split_pipex(cmd1, ' ');
	exec_command(command, envp);
	if (!command)
		exit (1);
	free(command);
}

void	do_pid2(int *pid, int *fds, char *cmd2, char **envp)
{
	char	**command;

	if (dup2(pid[0], STDIN_FILENO) == -1 || dup2 (fds[1], STDOUT_FILENO) == -1)
		exit(1);
	close (pid[0]);
	close (pid[1]);
	close(fds[0]);
	close(fds[1]);
	command = ft_split_pipex(cmd2, ' ');
	if (!command)
		exit (1);
	exec_command(command, envp);
	free(command);
}
