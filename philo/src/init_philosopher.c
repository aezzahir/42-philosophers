#include "../includes/philo.h"


void ft_init_philosopher(t_philo *philosopers, t_data *data, t_fork *forks)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers)
    {

        philosopers[i].id = i + 1;
        philosopers[i].data = data;


        philosopers[i].died = false;
        philosopers[i].number_of_meals_eaten = 0;
        philosopers[i].last_meal_time = 0;
    
        (&philosopers[i])->left_fork = &forks[i];
        (&philosopers[i])->right_fork = &forks[(i + 1) % data->number_of_philosophers];
        if (philosopers[i].id % 2 == 0)
            philosopers[i].eat_permission = true;
        else
            philosopers[i].eat_permission = false;
        philosopers[i].start_time = data->start_time;
        philosopers[i].time_to_die = data->time_to_die;
        philosopers[i].time_to_eat  = data->time_to_eat;
        philosopers[i].time_to_sleep = data->time_to_sleep;
        philosopers[i].number_of_times_each_philosopher_must_eat = data->number_of_times_each_philosopher_must_eat;
        i++;
    }
}