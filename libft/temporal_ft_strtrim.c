
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	// size_t len_set;
	size_t i;
	size_t j;

	// len_set = ft_strlen(set);
	j = 0;
	while (s1[j] != '\0')
	{
		i = 0;
		if (s1[j] == set[i])
		{
			while (set[i] == s1[j] && set[i] != '\0')
			{
				i++;
			}
			((char *)s1)[j] = s1[j + i];
		}
		j++;
	}
	return ((char *)s1);
}