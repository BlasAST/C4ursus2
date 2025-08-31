#include "pipex.h"

void do_pid1(int *pid, int fd1, char *cmd1, char **envp)
{
	char **command;

	dup2(fd1, STDIN_FILENO);
	dup2(pid[1], STDOUT_FILENO);
	close(pid[0]);
	close(pid[1]);
	command = ft_split(cmd1, ' ');
	exec_command(command, envp);
}

void do_pid2(int *pid, int fd2, char *cmd2, char **envp)
{
	char **command;

	dup2(pid[0], STDIN_FILENO);
	dup2 (fd2, STDOUT_FILENO);
	close (pid[0]);
	close (pid[1]);
	command = ft_split(cmd2, ' ');
	exec_command(command, envp);
    // while ((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    // 	write(STDOUT_FILENO, buffer, n);
}
