/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:43:18 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/11/11 13:15:00 by bsiguenc         ###   ########.fr       */
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

int	find_char(char *str, char t_char)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == t_char)
			return (1);
		i++;
	}
	return (0);
}

char	*try_routes(char *route, char *command)
{
	char *temp_path;
	char *temp;

	if (find_char(command, '/') == 1)
	{
		temp = command;
	}
	else
	{
		temp_path = ft_strjoin(route,"/");
		if (!temp_path)
			return (NULL);
		temp = ft_strjoin(temp, command);
		free (temp_path);
	}
	return (temp);
}

void	exec_command(char **command, char **envp)
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
		exit(1);
	}
	routes = ft_split(path, ':');
	while (routes[i] != NULL)
	{
		// route_temp = ft_strjoin(routes[i], ft_strjoin ("/", command[0]));
		route_temp = try_routes(routes[i], command[0]);
		if (access(route_temp, X_OK) == 0)
			exec_plus(route_temp, command, envp);
		free (route_temp);
		i++;
	}
	write(2, command[0], ft_strlen(command[0]));
	write (2, ": command not found\n", 20);
	exit(127);
}
