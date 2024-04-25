#include "../includes/philo.h"

// Define a struct to hold both the mutex and the flag

// Function to initialize the mutex and flag
void ft_init_fork(t_fork *fork)
{
    pthread_mutex_init(&(fork->mutex), NULL);
    fork->is_locked = false;
}

// Function to lock the mutex and set the flag
void ft_lock_fork(t_fork *fork)
{
    pthread_mutex_lock(&(fork->mutex));
    fork->is_locked = true;
}

// Function to unlock the mutex and clear the flag
void ft_unlockt_fork(t_fork *fork)
{
    fork->is_locked = false;
    pthread_mutex_unlock(&(fork->mutex));
}

// Function to check if the mutex is currently locked
bool ft_isForkLocked(t_fork *fork)
{
    return fork->is_locked;
}
