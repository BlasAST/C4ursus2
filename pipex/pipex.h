/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:51:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/14 13:41:04 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

int		check_file(char *file, int param);
void	do_pid1(int *pid, int *fds, char **cmds, char **envp);
void	do_pid2(int *pid, int *fds, char **cmds, char **envp);
void	exec_command(char **command, char **envp, char **cmds);
void	free_split(char **arr);
void	free_all(char **command, char **routes, char *route_temp);
char	**ft_split_pipex(char *str, char delimiter);
char	*new_str(char *str, int size);
int		jump_spaces(char **str);
int		size_str(char *str, char delimiter);
int		size_scapes(char *str);
char	*rm_scapes(char *str);
void	find_chars_scapes(char **strs);
void	error_ex(char *str);
void	end_program(char **routes, char **command, char **cmds);
void	frees_errors_routes(char **routes, char **command, char **cmds);
char	*try_routes(char *route, char *command);
void	close_fds(int *fds);
void	close_pids(int *pids);
#endif