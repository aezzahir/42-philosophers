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

    while (philo->data->number_of_times_each_philosopher_must_eat == -1 || philo->number_of_meals_eaten < philo->data->number_of_times_each_philosopher_must_eat)
    {
        if (philo->died)
        {
            printf("%lu %d  died\n", philo->death_time, philo->id);
            return (NULL);
        }
        if (philo->data->someone_died)
            return NULL;
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
void ft_init_philosopher(t_philo *philo, t_data *data)
{
    philo->start_time = get_current_time();
    philo->data = data;
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
int main2(int argc, char *argv[])
{
    t_data data;
    t_philo *philosopers;
    t_fork *forks;
    int i;

    if (argc != 5 && argc != 6)
    {
        printf("./phio number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n\n");
        return (0);
    }
    
    ft_parse_arguments(argc, argv, &data);
    //print_data(&data);
    forks = NULL;
    philosopers = NULL;
    if (data.number_of_philosophers > 0)
    {
        forks = ft_forks(data.number_of_philosophers);
        philosopers = (t_philo *)malloc(data.number_of_philosophers * sizeof(t_philo));
    }
    i = 0;
    while (i < data.number_of_philosophers)
    {
        ft_init_philosopher(&philosopers[i], &data);
        (&philosopers[i])->left_fork = &forks[i];
        (&philosopers[i])->right_fork = &forks[(i + 1) % data.number_of_philosophers];
        philosopers[i].id = i + 1;
        philosopers[i].number_of_meals_eaten = 0;
        philosopers[i].last_meal_time = 0;
        philosopers[i].died = false;
        pthread_create(&(philosopers[i].thread), NULL, philo_routine, (void *)&philosopers[i]);
        if (philosopers[i].id % 2 == 0)
            philosopers[i].eating_permission = true;
        else
            philosopers[i].eating_permission = false;
        i++;
    }
    i = 0;
    while (i < data.number_of_philosophers)
    {
        pthread_join(philosopers[i].thread, NULL);
        i++;
    }
    if (data.number_of_philosophers > 0)
    {
        free(forks);
        free(philosopers);
    }
    return(0);
}
int main(int argc, char *argv[])
{
    main2(argc, argv);
    //system ("leaks philo");
    return (0);
}