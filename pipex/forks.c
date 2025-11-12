/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:03:45 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/12 12:46:03 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pid1(int *pid, int *fds, char **cmds, char **envp)
{
	char	**command;

	if (dup2(fds[0], STDIN_FILENO) == -1 || dup2(pid[1], STDOUT_FILENO) == -1)
		exit(1);
	close(pid[0]);
	close(pid[1]);
	close(fds[0]);
	close(fds[1]);
	command = ft_split_pipex(cmds[0], ' ');
	if (!command)
	{
		free_split(cmds);
		exit (1);
	}
	exec_command(command, envp, cmds);
	free_split(cmds);
	free_split(command);
	exit(127);
}

void	do_pid2(int *pid, int *fds, char **cmds, char **envp)
{
	char	**command;

	if (dup2(pid[0], STDIN_FILENO) == -1 || dup2 (fds[1], STDOUT_FILENO) == -1)
		exit(1);
	close (pid[0]);
	close (pid[1]);
	close(fds[0]);
	close(fds[1]);
	command = ft_split_pipex(cmds[1], ' ');
	if (!command)
	{
		free_split(cmds);
		exit (1);
	}
	exec_command(command, envp, cmds);
	free_split(cmds);
	free_split(command);
	exit(127);
}
