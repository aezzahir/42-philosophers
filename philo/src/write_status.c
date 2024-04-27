#include "../includes/philo.h"



void    write_status(t_philo *philo, char *status, char *color)
{
    size_t current_time;
    if (philo->died)
    {
        pthread_mutex_lock(&philo->data->death_mutex);
        philo->data->someone_died = true;
        pthread_mutex_unlock(&philo->data->death_mutex);
        pthread_mutex_lock(&philo->data->write_mutex);
        current_time = get_current_time() - philo->start_time;
        printf("%s", color);
        printf("%lu %d %s\n", current_time, philo->id, status);
        printf("\033[0m");
        ft_usleep(10);
        pthread_mutex_unlock(&philo->data->write_mutex);
        return;
    }
    else if(ft_end(philo))
        return;
    pthread_mutex_lock(&philo->data->write_mutex);
    current_time = get_current_time() - philo->start_time;
    printf("%s", color);
    printf("%lu %d %s\n", current_time, philo->id, status);
    printf("\033[0m");
    pthread_mutex_unlock(&philo->data->write_mutex);
}