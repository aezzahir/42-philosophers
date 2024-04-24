#include "../includes/philo.h"


void print_data(t_data *data)
{
    printf(" number_of_philosophers = %d \n time_to_die = %d\n time_to_eat =  %d\n time_to_sleep =  %d\n number_of_times_each_philosopher_must_eat =  %d\n",
    data->number_of_philosophers, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->number_of_times_each_philosopher_must_eat);
}
 
void philo_routine(void *philo)
{
    think();
    sleep();
    eat();
    die();
}



pthread_mutex_t *ft_forks(int number_of_philosophers)
{
    pthread_mutex_t *forks;
    int i;
    forks = (pthread_mutex_t *)malloc(number_of_philosophers * sizeof(pthread_mutex_t));
    if(!forks)
        return (NULL);
    i = 0;
    while (i < number_of_philosophers)
    {
        if (pthread_mutex_init(&forks[i++], NULL) != 0)
            printf("Failled to init fork %d\n", i);
    }
    return forks;
}

int main(int argc, char *argv[])
{
    t_data data;
    t_philo *philosopers;
    pthread_mutex_t *forks;
    
    if (6 < argc)
        printf("./phio number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n\n");
    
    ft_parse_arguments(argc, argv, &data);
    print_data(&data);

    forks = ft_forks(data.number_of_philosophers);
    philosopers = (t_philo *)malloc(data.number_of_philosophers * sizeof(t_philo));
    

    return(0);
}