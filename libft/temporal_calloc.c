
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t i;
	void *pointer;

	if (nmemb > 0 && size > 0)
	{
		pointer = malloc (nmemb * size);
		if (!pointer)
			return (NULL);
		i = 0;
		while (i < nmemb * size)
			((char *)pointer)[i] = '\0';
		return (pointer);
	}
	return (NULL);
}