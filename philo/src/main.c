#include "../includes/philo.h"


void print_data(t_data *data)
{
    printf(" number_of_philosophers = %d \n time_to_die = %d\n time_to_eat =  %d\n time_to_sleep =  %d\n number_of_times_each_philosopher_must_eat =  %d\n",
    data->number_of_philosophers, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->number_of_times_each_philosopher_must_eat);
}
 
int main(int argc, char *argv[])
{
    t_data data;
    
    if (6 < argc)
        printf("./phio number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n\n");
    
    ft_parse_arguments(argc, argv, &data);
    print_data(&data);


    return(0);
}