/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:43:18 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/12 13:17:04 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char *str)
{
	char	*path;
	int		i;

	path = "PATH=";
	i = 0;
	while (*str == path[i] && path[i] != '\0' && *str != '\0')
	{
		str++;
		i++;
	}
	if (path[i] == '\0')
		return (1);
	return (0);
}

char	*get_path(char **envp)
{
	char	*path;

	while (find_path(*envp) == 0)
	{
		envp++;
	}
	if (*envp == NULL)
		return (NULL);
	return (*envp + 5);
}

void	exec_plus(char *route_temp, char **command, char **envp)
{
	execve(route_temp, command, envp);
	perror ("execve failed");
	free(route_temp);
	exit(127);
}

void	exec_command(char **command, char **envp, char **cmds)
{
	char	*path;
	char	**routes;
	char	*route_temp;
	int		i;

	i = 0;
	path = get_path(envp);
	if (!path)
	{
		perror ("No PATH found");
		free_split(command);
		exit(1);
	}
	routes = ft_split(path, ':');
	while (routes[i] != NULL)
	{
		route_temp = try_routes(routes[i], command[0]);
		if (!route_temp)
			frees_errors_routes(routes, command, cmds);
		if (access(route_temp, X_OK) == 0)
			exec_plus(route_temp, command, envp);
		free (route_temp);
		i++;
	}
	end_program(routes, command, cmds);
}
