#include "../includes/philo.h"


int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		if (ft_end(philo))
        	return (-1);
		usleep(500);
	}
	return (0);
}
