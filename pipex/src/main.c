/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:43:28 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/01 14:53:16 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	do_forks(int *pipe_fd, int *fds, char **cmds, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		perror ("Error en fork");
	if (pid1 == 0)
		status = do_pid1(pipe_fd, fds, cmds[0], envp);
	pid2 = fork();
	if (pid2 == -1)
		perror ("Error en fork");
	if (pid2 == 0)
		status = do_pid2(pipe_fd, fds, cmds[1], envp);
	close (pipe_fd[0]);
	close (pipe_fd[1]);
	waitpid (pid1, NULL, 0);
	waitpid (pid2, NULL, 0);
	return (status);
}

int	pipex(char *file1, char **cmds, char *file2, char **envp)
{
	int		pipe_fd[2];
	int		fds[2];
	int		status;

	fds[0] = check_file(file1, 0);
	fds[1] = check_file(file2, 1);
	if (fds[1] == -1)
	{
		return (1);
	}
	if (pipe(pipe_fd) == -1)
		perror("Error en la creación del pipe");
	status = do_forks(pipe_fd, fds, cmds, envp);
	close(fds[0]);
	close(fds[1]);
	return (0);
}

int	main(int argn, char **args, char **envp)
{
	char	**cmds;
	int		exit_status;

	exit_status = 0;
	if (argn != 5)
		return (1);
	cmds = (char **)malloc(sizeof(char *) * 3);
	if (!cmds)
		return (1);
	cmds[0] = ft_strdup(args[2]);
	cmds[1] = ft_strdup(args[3]);
	cmds[2] = NULL;
	exit_status = pipex(args[1], cmds, args[4], envp);
	free(cmds[0]);
	free(cmds[1]);
	free(cmds);
	return (exit_status);
}
