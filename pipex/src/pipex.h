/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:51:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/09/02 16:33:26 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

int		check_file(char *file, int param);
int		do_pid1(int *pid, int *fds, char *cmd1, char **envp);
int		do_pid2(int *pid, int *fds, char *cmd2, char **envp);
int		exec_command(char **command, char **envp);
void	free_split(char **arr);
void	free_all(char **command, char **routes, char *route_temp);
#endif