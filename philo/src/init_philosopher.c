/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:33:14 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/27 21:51:37 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_philosopher(t_philo *philosopers, t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philosopers[i].id = i + 1;
		philosopers[i].data = data;
		philosopers[i].died = false;
		philosopers[i].number_of_meals_eaten = 0;
		philosopers[i].last_meal_time = 0;
		(&philosopers[i])->left_fork = &forks[i];
		(&philosopers[i])->right_fork
			= &forks[(i + 1) % data->number_of_philosophers];
		philosopers[i].eat_permission = false;
		if (philosopers[i].id % 2 == 0)
			philosopers[i].eat_permission = true;
		philosopers[i].number_of_philosophers = data->number_of_philosophers;
		philosopers[i].start_time = data->start_time;
		philosopers[i].time_to_die = data->time_to_die;
		philosopers[i].time_to_eat = data->time_to_eat;
		philosopers[i].time_to_sleep = data->time_to_sleep;
		philosopers[i].number_of_times_each_philosopher_must_eat
			= data->number_of_times_each_philosopher_must_eat;
		i++;
	}
}

t_fork	*ft_forks(int number_of_philosophers)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(number_of_philosophers * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
		ft_init_fork(&forks[i++]);
	return (forks);
}

void	ft_cleanup(t_philo *philosophers, t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		ft_destroy_fork(&forks[i]);
		i++;
	}
	if (philosophers)
		free(philosophers);
	if (forks)
		free(forks);
	pthread_mutex_destroy(&(data->death_mutex));
	pthread_mutex_destroy(&(data->write_mutex));
}
