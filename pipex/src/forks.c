#include "pipex.h"

void do_pid1(int *pid, int fd1, char *cmd1, char **envp)
{
	dup2(fd1, STDIN_FILENO);
	dup2(pid[1], STDOUT_FILENO);
	close(pid[0]);
	close(pid[1]);
	write (1, "Desde el hijo cabron\n", 21);
	char *argv[] = {cmd1, NULL};
	execve("/bin/cat", argv, envp);
	perror("execve error");
    exit(1);
}
// printf("Soy el hijo 1\n %s \n", cmd1);

void do_pid2(int *pid, int fd2, char *cmd2, char **envp)
{
	char buffer[1024];
	int	n;

	dup2(pid[0], STDIN_FILENO);
	close (pid[0]);
	close (pid[1]);
    while ((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    	write(STDOUT_FILENO, buffer, n);
}
