/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:03:45 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/14 13:45:46 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pid1(int *pid, int *fds, char **cmds, char **envp)
{
	char	**command;

	if (dup2(fds[0], STDIN_FILENO) == -1 || dup2(pid[1], STDOUT_FILENO) == -1)
		exit(1);
	close_fds(fds);
	close_pids(pid);
	command = ft_split_pipex(cmds[0], ' ');
	if (!command || !command[0] || command[0][0] == '\0')
	{
		write(2, "pipex: command not found: \n", 27);
		if (command)
			free_split(command);
		free_split(cmds);
		exit (127);
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
	close_fds(fds);
	close_pids(pid);
	command = ft_split_pipex(cmds[1], ' ');
	if (!command || !command[0] || command[0][0] == '\0')
	{
		write(2, "pipex: command not found: \n", 27);
		if (command)
			free_split(command);
		free_split(cmds);
		exit (127);
	}
	exec_command(command, envp, cmds);
	free_split(cmds);
	free_split(command);
	exit(127);
}
