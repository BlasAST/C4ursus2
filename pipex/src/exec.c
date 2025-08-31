#include "pipex.h"

int	find_path(char *str)
{
	char *path;
	int	i;

	path = "PATH=";
	i = 0;
	while (*str != '\0')
	{
		if (*str == path[i])
		{
			while (*str == path[i] && path[i] != '\0' && *str != '\0')
			{
				str++;
				i++;
			}
			if (path[i] == '\0')
				return (1);
			i = 0;
		}
		str++;
	}
	return (0);
}

char *get_path(char **envp)
{
	char *path;

	while (find_path(*envp) == 0)
	{
		envp++;
	}
	path = ft_strdup(*envp);
	path += 5;
	return (path);
}

void	exec_command(char **command, char **envp)
{
	char *path;
	char **routes;
	char	*route_temp;

	path = get_path(envp);
	if (!path)
	{
		perror ("No PATH found");
		exit (1);
	}
	routes = ft_split(path, ':');
	while (*routes != NULL)
	{

		route_temp = ft_strjoin(*routes, ft_strjoin ("/", command[0]));
		if (access(route_temp, X_OK) == 0)
		{
			execve(route_temp, command, envp);
			perror ("execve failed");
			exit (1);
		}
		free (route_temp);
		routes++;
	}
	ft_printf("%s: command not found\n", command[0]);
}