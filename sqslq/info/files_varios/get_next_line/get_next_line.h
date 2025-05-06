#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_clean_last_buff(char **last, char *buff, int bytes);
int	ft_strlen(char *str);
int ft_find(char *str, char c);
char	*ft_strdup(char *str);
void	ft_strcpy(char *dest, char *str, char c);
char	*ft_realloc(char *last_buffer, char *buffer);
#endif