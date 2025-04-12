#include "libft.h"
#include <stdio.h>


int	ft_atoi(const char *nptr)
{
	int	number;
	int neg;

	number = 0;
	neg = 0;
	while (*nptr == ' ' || *nptr >= 9 && *nptr <= 13)
			nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + *nptr - '0';
		nptr++;
	}
	if (neg)
		number*= -1;
	return (number);
}

/*
int main(void)
{
	char *a = "\n   -l12341a611";
	printf("%d\n\n", atoi(a));
	printf("%d", ft_atoi(a));
} */