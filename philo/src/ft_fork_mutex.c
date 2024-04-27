/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:39:52 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/27 21:42:08 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_fork(t_fork *fork)
{
	pthread_mutex_init(&(fork->mutex), NULL);
	pthread_mutex_init(&(fork->key), NULL);
	pthread_mutex_lock(&(fork->key));
	fork->is_locked = false;
	pthread_mutex_unlock(&(fork->key));
}

void	ft_lock_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	pthread_mutex_lock(&(fork->key));
	fork->is_locked = true;
	pthread_mutex_unlock(&(fork->key));
}

void	ft_unlockt_fork(t_fork *fork)
{
	pthread_mutex_unlock(&(fork->mutex));
	pthread_mutex_lock(&(fork->key));
	fork->is_locked = false;
	pthread_mutex_unlock(&(fork->key));
}

bool	ft_is_fork_locked(t_fork *fork)
{
	bool	status;

	pthread_mutex_lock(&(fork->key));
	status = fork->is_locked;
	pthread_mutex_unlock(&(fork->key));
	return (status);
}

void	ft_destroy_fork(t_fork *fork)
{
	pthread_mutex_destroy(&(fork->mutex));
	pthread_mutex_destroy(&(fork->key));
}
