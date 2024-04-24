#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>

typedef struct s_arguments
{
    int number_of_philosophers;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_data;



typedef struct s_philo {
    int philo_id;                 // Philosopher ID (1 to number_of_philosophers)
    int number_of_meals_eaten;     // Number of meals eaten by this philosopher
    int last_meal_time;            // Timestamp of the philosopher's last meal (milliseconds)

    // Mandatory part (mutexes)
    pthread_mutex_t left_fork_mutex;  // Mutex for the philosopher's left fork
    pthread_mutex_t right_fork_mutex; // Mutex for the philosopher's right fork

    // Bonus part (semaphores - optional placeholder)
    // You'll need to replace this with a semaphore if implementing the bonus part
    // int forks_available; // Semaphore to represent available forks (initialize in main)

} t_philo;


void ft_parse_arguments(int argc, char *argv[], t_data *data);













size_t	ft_atoi(const char *str);
size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);



































#endif