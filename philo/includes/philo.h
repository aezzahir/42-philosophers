#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for write and usleep
#include <string.h>
#include <stdbool.h> // for boolean ... true false
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>


typedef struct s_arguments
{
    int number_of_philosophers;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_data;

typedef struct s_fork
{
    pthread_mutex_t mutex;
    bool is_locked;
} t_fork;

/* Forks functions */
void ft_init_fork(t_fork *fork);
void ft_lock_fork(t_fork *fork);
void ft_unlockt_fork(t_fork *fork);
bool ft_isForkLocked(t_fork *fork);











typedef struct s_philo {
    int id;                 // Philosopher ID (1 to number_of_philosophers)
    pthread_t thread;
    t_data *data; //pointer to data;
    size_t start_time;
    int number_of_meals_eaten;     // Number of meals eaten by this philosopher
    int last_meal_time;            // Timestamp of the philosopher's last meal (milliseconds)
    // Mandatory part (mutexes)
    bool eating_permission;
    t_fork *left_fork;  // Mutex for the philosopher's left fork
    t_fork *right_fork; // Mutex for the philosopher's right fork

    // Bonus part (semaphores - optional placeholder)
    // You'll need to replace this with a semaphore if implementing the bonus part
    // int forks_available; // Semaphore to represent available forks (initialize in main)

} t_philo;



/**/

void *philo_routine(void *philo);

/**Parsing functions*/
void ft_parse_arguments(int argc, char *argv[], t_data *data);
size_t	ft_atoi(const char *str);




/* Routine function */
void    ft_sleep(t_philo *philo);
void    ft_eat(t_philo *philo);
void    ft_think(t_philo *philo);
void    ft_take_a_fork(t_philo *philo, t_fork *fork);

bool    ft_check_death(t_philo *philo);
bool    ft_check_eating_permission(t_philo *philo);



/** helper functions */
size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);



































#endif