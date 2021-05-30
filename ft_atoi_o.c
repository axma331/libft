#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] && (('\t' <= s[i] && s[i] <= '\r') || s[i] == ' '))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && ('0' <= s[i] && s[i] <= '9'))
	{
		num = 10 * num + (s[i] - '0') * sign;
		if (num > INT32_MAX)
			return (0);
		if (num < INT32_MIN)
			return (0);
		i++;
	}
	return (num);
}
