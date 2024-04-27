#include "../includes/philo.h"

// Define a struct to hold both the mutex and the flag

// Function to initialize the mutex and flag
void ft_init_fork(t_fork *fork)
{
    pthread_mutex_init(&(fork->mutex), NULL);
    pthread_mutex_init(&(fork->key), NULL);
    pthread_mutex_lock(&(fork->key));
    fork->is_locked = false;
    pthread_mutex_unlock(&(fork->key)); 
}

// Function to lock the mutex and set the flag
void ft_lock_fork(t_fork *fork)
{
    pthread_mutex_lock(&(fork->mutex));

    pthread_mutex_lock(&(fork->key));
    fork->is_locked = true;
    pthread_mutex_unlock(&(fork->key));
}

// Function to unlock the mutex and clear the flag
void ft_unlockt_fork(t_fork *fork)
{
    pthread_mutex_unlock(&(fork->mutex));
    pthread_mutex_lock(&(fork->key));
    fork->is_locked = false;
    pthread_mutex_unlock(&(fork->key)); 
}

// Function to check if the mutex is currently locked
bool ft_isForkLocked(t_fork *fork)
{
    bool status;

    pthread_mutex_lock(&(fork->key));
    status = fork->is_locked;
    pthread_mutex_unlock(&(fork->key));
    return status;
}
