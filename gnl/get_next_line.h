/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:45:00 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/05/05 13:22:50 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_clean_last_buff(char **last, char *buffer);
void		ft_print_buffer(char *str);
int			ft_strlen(char *str);
char		*ft_strdup(char *str);
int		ft_find(char *str, char c);
void		ft_strcpy(char *dest, char *str, char c);
char		*ft_realloc_buff(char *last_buff, char *str);
#endif