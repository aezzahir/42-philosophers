#include "../includes/philo.h"


void print_data(t_data *data)
{
    printf(" number_of_philosophers = %d \n time_to_die = %lu\n time_to_eat =  %lu\n time_to_sleep =  %lu\n number_of_times_each_philosopher_must_eat =  %d\n",
    data->number_of_philosophers, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->number_of_times_each_philosopher_must_eat);
}
 
void *philo_routine(void *a_philo)
{
    t_philo *philo;
    philo = (t_philo *)a_philo;

    while (!ft_end(philo))
    {
        ft_eat(philo);
        ft_sleep(philo);
        ft_think(philo);
    }
    return (NULL);
}



t_fork *ft_forks(int number_of_philosophers)
{
    t_fork *forks;
    int i;
    forks = (t_fork *)malloc(number_of_philosophers * sizeof(t_fork));
    if(!forks)
        return (NULL);
    i = 0;
    while (i < number_of_philosophers)
    {
        ft_init_fork(&forks[i++]);
    }
    return forks;
}

bool ft_check_if_a_philo_died(t_philo *philosophers)
{
    int i;

    i = 0;
    while (i < philosophers[0].data->number_of_philosophers)
    {
        if(philosophers[i].died)
        {

            printf("%lu %d  died\n", philosophers[i].death_time, philosophers[i].id);
            return (true);
        }
        i++;
    }
    return (false);
}



int main(int argc, char *argv[])
{
    t_data data;
    t_philo *philosophers;
    t_fork *forks;

    if (argc != 5 && argc != 6)
    {
        printf("./phio number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n\n");
        return (0);
    }
    
    ft_parse_arguments(argc, argv, &data);
    forks = NULL;
    philosophers = NULL;
    if (data.number_of_philosophers > 0)
    {
        forks = ft_forks(data.number_of_philosophers);
        philosophers = (t_philo *)malloc(data.number_of_philosophers * sizeof(t_philo));
    }
    ft_init_philosopher(philosophers, &data, forks);
    ft_run_simulation(philosophers, &data);
    ft_cleanup(philosophers, &data, forks);
    system("leaks philo");
    return(0);
}


void ft_run_simulation(t_philo *philosophers, t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_create(&(philosophers[i].thread), NULL, philo_routine, (void *)&philosophers[i]);
        i++;
    }
    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
    i = 0;
    while (i < data->number_of_philosophers)
    {
        if (philosophers[i].died)
        {
            printf("%lu %d  died\n", philosophers[i].death_time, philosophers[i].id);
            break;
        }
        i++;
    }
}
