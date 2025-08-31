#include "pipex.h"

void	do_forks(int *pipe_fd, int *fds, char *cmd1, char *cmd2, char **envp)
{
	pid_t pid1;
	pid_t pid2;

	pid1 = fork();
	if (pid1 == -1)
		perror ("Error en fork");
	if (pid1 == 0)
		do_pid1(pipe_fd, fds[0], cmd1, envp);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			perror ("Error en fork");
		if (pid2 == 0)
			do_pid2(pipe_fd, fds[1], cmd2, envp);
		else
		{
			close (pipe_fd[0]);
			close (pipe_fd[1]);
			waitpid (pid1, NULL, 0);
			waitpid (pid2, NULL, 0);
		}
	}
}

void pipex(char *file1, char *cmd1, char *cmd2, char *file2, char **envp)
{
	int	pipe_fd[2];
    int fds[2];
    char *message;

    fds[0] = check_file(file1, &message, 0);
	fds[1] = check_file(file2, &message, 1);
	if (fds[0] == -1 || fds[1] == -1)
	{
		perror(message);
		return ;
	}
	if (pipe(pipe_fd) == -1)
		perror("Error en la creación del pipe");
	do_forks(pipe_fd, fds, cmd1, cmd2, envp);
	close(fds[0]);
	close(fds[1]);
}

int main(int argn, char **args, char **envp)
{
    if (argn != 5)
        return (0);
    pipex(args[1], args[2], args[3], args[4], envp);
    return (0);
}
