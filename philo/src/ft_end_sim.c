/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:29:19 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/28 09:36:52 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	ft_check_death(t_philo *philo)
{
	size_t	time_since_last_meal;
	size_t	current_time;

	current_time = get_current_time() - philo->start_time;
	time_since_last_meal = current_time - philo->last_meal_time;
	if (time_since_last_meal > philo->time_to_die)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		philo->data->someone_died = true;
		philo->death_time = current_time;
		philo->died = true;
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (true);
	}
	return (false);
}



bool	ft_philo_is_full(t_philo *philo)
{
	return (philo->number_of_meals_eaten
		== philo->number_of_times_each_philosopher_must_eat);
}

bool	ft_end(t_philo *philo)
{
	bool	status;

	if (ft_philo_is_full(philo))
		return (true);
	pthread_mutex_lock(&philo->data->death_mutex);
	status = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (status)
		return (status);
	status = ft_check_death(philo);
	return (status);
}
