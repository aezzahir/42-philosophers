#include "../includes/philo.h"


void ft_parse_arguments(int argc, char *argv[], t_data *data)
{
    pthread_mutex_init(&(data->write_mutex), NULL);
    data->start_time = get_current_time();
    data->someone_died = false;
    data->number_of_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (6 == argc)
        data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else if (5 == argc)
        data->number_of_times_each_philosopher_must_eat = -1;
}