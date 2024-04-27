#include "../includes/philo.h"


void    ft_eat(t_philo *philo)
{
    size_t current_time;

    if (ft_end(philo))
        return;
    if (philo->eat_permission)
    {
        ft_take_a_fork(philo, philo->left_fork);
        ft_take_a_fork(philo, philo->right_fork);
    }
    else
        return;

    current_time = get_current_time() - philo->start_time;
    philo->last_meal_time = get_current_time() - philo->start_time; // update last meal time 

    printf("%lu %d  is eating\n", current_time, philo->id);
    ft_usleep(philo->time_to_eat);
    philo->number_of_meals_eaten++;                                 // increment number of meals eaten
    ft_unlockt_fork(philo->left_fork);
    ft_unlockt_fork(philo->right_fork);
    philo->eat_permission = false;                               // no permission to eat
}


void    ft_take_a_fork(t_philo *philo, t_fork *fork)
{
    size_t current_time;

    current_time = get_current_time() - philo->start_time;
    ft_lock_fork(fork);
    printf("%lu %d   has taken a fork\n", current_time, philo->id);
}


void    ft_sleep(t_philo *philo)
{
    size_t current_time;

    if (ft_end(philo))
        return;
    current_time = get_current_time() - philo->start_time;
    printf("%lu %d  is sleeping\n", current_time, philo->id);
    ft_usleep(philo->time_to_sleep);
}



void    ft_think(t_philo *philo)
{
    size_t current_time;

    if (ft_end(philo))
        return;
    current_time = get_current_time() - philo->start_time;
    printf("%lu %d  is thinking\n", current_time, philo->id);
    while (!ft_check_eating_permission(philo))
    {
        if (ft_end(philo))
            return;
    }
    philo->eat_permission = true;
}



bool ft_check_death(t_philo *philo)
{
    size_t time_since_last_meal;
    size_t current_time;
    current_time = get_current_time() - philo->start_time;
    time_since_last_meal = current_time - philo->last_meal_time;
    if (time_since_last_meal > philo->time_to_die)
    {
        philo->death_time = current_time;
        philo->died = true;
        pthread_mutex_lock(&philo->data->write_mutex);
        philo->data->someone_died = true;
        pthread_mutex_unlock(&philo->data->write_mutex);
        printf("%lu %d  died\n", current_time, philo->id);
        return (true);
    }
    return (false);
}

bool    ft_check_eating_permission(t_philo *philo)
{
    return (philo->number_of_philosophers > 1 && !ft_isForkLocked(philo->left_fork) && !ft_isForkLocked(philo->right_fork));
}


bool    ft_philo_is_full(t_philo *philo)
{
    return (philo->number_of_meals_eaten == philo->number_of_times_each_philosopher_must_eat);
}


bool ft_end(t_philo *philo)
{
    bool status;

    if (ft_philo_is_full(philo))
        return (true);
    pthread_mutex_lock(&philo->data->write_mutex);
    status = philo->data->someone_died;
    pthread_mutex_unlock(&philo->data->write_mutex);
    if (status)
        return (status);
    status = ft_check_death(philo);
    return (status);
}