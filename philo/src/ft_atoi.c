#include "../includes/philo.h"

size_t	ft_atoi(const char *str)
{
	size_t			digit;
	size_t			sign;
	size_t			result;
	size_t			i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		result = result * 10 + digit;
		if (result > INT_MAX)
			result = (long int)INT_MAX + 1;
		if (result < INT_MIN)
			result = (long int)INT_MIN - 1;
		i++;
	}
	return (sign * result);
}