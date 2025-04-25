/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:37:22 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/25 18:33:47 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_print_buff(char *buffer)
{
	while (*buffer)
	{
		write(1, buffer, 1);
		buffer++;
	}
}
char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	int	bytes;

	if (fd == 0)
		bytes = read(0, buffer, BUFFER_SIZE - 1);
	else
		bytes = read(fd, buffer, BUFFER_SIZE - 1);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		ft_print_buff(buffer);
		bytes = read(fd, buffer, BUFFER_SIZE - 1);
	}
	return (NULL);
}
int	main(int args, char **argv)
{
	if (NULL == 0)
		printf("Aqui tamo");
	int	file = open("nidea.txt", O_RDONLY);
	get_next_line(file);
}
