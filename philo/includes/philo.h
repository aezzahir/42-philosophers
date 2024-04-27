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
    pthread_mutex_t write_mutex; // cleanUp
    pthread_mutex_t death_mutex; // cleanUp
    bool someone_died;
    int number_of_philosophers;
    size_t  start_time;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

} t_data;

typedef struct s_fork
{
    pthread_mutex_t mutex;
    pthread_mutex_t key;
    bool is_locked;
} t_fork;

/* Forks functions */
void ft_init_fork(t_fork *fork);
void ft_lock_fork(t_fork *fork);
void ft_unlockt_fork(t_fork *fork);
void ft_destroy_fork(t_fork *fork);
bool ft_isForkLocked(t_fork *fork);











typedef struct s_philo {
    int             id;                 // Philosopher ID (1 to number_of_philosophers)
    pthread_t       thread;
   
    t_data *data; //pointer to data;
    bool died;
    bool    eat_permission;
    // duplicate the content of data for each philo
    int number_of_philosophers;
    size_t  start_time;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t death_time;
    int number_of_times_each_philosopher_must_eat;



    int number_of_meals_eaten;     // Number of meals eaten by this philosopher
    int last_meal_time;            // Timestamp of the philosopher's last meal (milliseconds)

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
void ft_init_philosopher(t_philo *philosopers, t_data *data, t_fork *forks);



/* Routine function */
void    ft_sleep(t_philo *philo);
void    ft_eat(t_philo *philo);
void    ft_think(t_philo *philo);
void    ft_take_a_fork(t_philo *philo, t_fork *fork);

bool    ft_check_eating_permission(t_philo *philo);



bool ft_check_death(t_philo *philo);
bool    ft_philo_is_full(t_philo *philo);
bool ft_end(t_philo *philo);

/** helper functions */
size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);











void    write_status(t_philo *philo, char *status, char *color);



void ft_cleanup(t_philo *philosophers, t_data *data, t_fork *forks);














#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

#define BLACK "\033[0;30m"
#define GRAY "\033[0;37m"

#define BRIGHT_RED "\033[1;91m"
#define BRIGHT_GREEN "\033[1;92m"
#define BRIGHT_YELLOW "\033[1;93m"
#define BRIGHT_BLUE "\033[1;94m"
#define BRIGHT_PURPLE "\033[1;95m"
#define BRIGHT_CYAN "\033[1;96m"
#define BRIGHT_WHITE "\033[1;97m"




#endif