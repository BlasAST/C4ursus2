
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && (i + j) < len)
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
				
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *a = "Hola no buenas noches";
	char *b = "no";
	char *c = ft_strnstr(a,b,21);
	printf("%s", c);
}
*/