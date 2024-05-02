#include "../includes/philo.h"

void take(t_philo *philo, t_fork *fork)
{
	ft_lock_fork(fork);
    philo->nb_forks++;
	write_status(philo, "has taken a fork", PURPLE);
}
void	put(t_philo *philo, t_fork *fork)
{
	ft_unlockt_fork(fork);
    philo->nb_forks--;
}

void	ft_fork(t_philo *philo, int index, void f(t_philo *philo, t_fork *fork))
{
    if (index == -1)
        f(philo, philo->left_fork);
    else if (index == 1)
         f(philo, philo->right_fork);
    else if (index == -2)
    {
        f(philo, philo->left_fork);
        f(philo, philo->right_fork);
    }
    else if (index == 2)
    {
        f(philo, philo->right_fork);
        f(philo, philo->left_fork);
    }
    else
        write_status(philo, "ERROR HANDLING FORKS", RED);
}