/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:44:26 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/27 21:59:29 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *a_philo)
{
	t_philo	*philo;

	philo = (t_philo *)a_philo;
	while (!ft_end(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philosophers;
	t_fork	*forks;

	if (argc != 5 && argc != 6)
	{
		printf("./phio nb_of_philosophers t_die t_eat t_sleep [nb_of_meals]\n");
		return (0);
	}
	ft_parse_arguments(argc, argv, &data);
	forks = NULL;
	philosophers = NULL;
	if (data.number_of_philosophers > 0)
	{
		forks = ft_forks(data.number_of_philosophers);
		philosophers = (t_philo *)malloc(data.number_of_philosophers
				* sizeof(t_philo));
	}
	ft_init_philosopher(philosophers, &data, forks);
	ft_run_simulation(philosophers, &data);
	ft_cleanup(philosophers, &data, forks);
	return (0);
}

void	ft_run_simulation(t_philo *philosophers, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&(philosophers[i].thread), NULL,
			philo_routine, (void *)&philosophers[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
	while (--i >= 0)
	{
		if (philosophers[i].died)
		{
			printf("%lu %d  died\n",
				philosophers[i].death_time, philosophers[i].id);
			break ;
		}
	}
}
