#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t i;

	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while ((size_t) start < len && s[len])
	{
		substr[i] = ((char *)s)[start];
		i++;
		start++;
	}
	return (substr);
}

/*
	char * a = "Como tu te iama yo no se";
	char *c = ft_substr(a,8,6);
	printf ("%s \n \n %p  ----- %p", c, a, c);

*/