#include "../includes/philo.h"

size_t	ft_atoi(const char *str)
{
	int			digit;
	int			sign;
	int			result;
	int			i;

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
		i++;
	}
	result = sign * result;
	if (result < 0)
		return (0);
	return (size_t)(result);
}