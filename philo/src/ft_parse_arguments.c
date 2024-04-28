/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:43:19 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/28 10:40:57 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	ft_parse_arguments(int argc, char *argv[], t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((int)ft_atoi(argv[i]) < 0 || (int)ft_atoi(argv[i]) > INT_MAX)
			return (false);
		i++;
	}
	pthread_mutex_init(&(data->write_mutex), NULL);
	pthread_mutex_init(&(data->death_mutex), NULL);
	data->start_time = get_current_time();
	data->someone_died = false;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (6 == argc)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else if (5 == argc)
		data->number_of_times_each_philosopher_must_eat = -1;
	return (true);
}
