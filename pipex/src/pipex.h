#ifndef PIPEX_H
# define PIPEX_h
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
int	check_file(char *file, char **message, int param);
void	do_pid1(int *pid, int fd1, char *cmd1, char **envp);
void	do_pid2(int *pid, int fd2, char *cmd2, char **envp);
void	exec_command(char **command, char **envp);
#endif