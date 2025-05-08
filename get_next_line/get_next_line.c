/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:43:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/05/08 14:28:01 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_last_buff(char **last, char *buff)
{
	char	*temp;

	free(buff);
	if (*last)
	{
		temp = ft_strdup(*last);
		free (*last);
		*last = NULL;
		return (temp);
	}
	return (NULL);
}

char	*modify_last_buff(char **buffer, char **last_buffer)
{
	int		pos;
	char	*temp;

	free(*buffer);
	pos = ft_find(*last_buffer, '\n');
	temp = malloc(sizeof(char) * pos + 2);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, *last_buffer, '\n');
	*last_buffer = ft_strdup(*last_buffer + pos + 1);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*last_buffer;
	char		*buffer;
	char		*temp;
	int			bytes;
	int			pos;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !fd)
		return (NULL);
	while (ft_find(last_buffer, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_clean_last_buff(&last_buffer, buffer));
		buffer[bytes] = '\0';
		last_buffer = ft_realloc(last_buffer, buffer);
	}
	return (modify_last_buff(&buffer, &last_buffer));
}
