/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:17:05 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/28 09:42:48 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



void	ft_think(t_philo *philo)
{
	write_status(philo, "is thinking", YELLOW);
	while(!ft_end(philo) && philo->nb_forks < 2)
	{
		if (philo->eat_permission)
		{
			if(!locked(philo->left_fork) || !locked(philo->right_fork))
				ft_fork(philo, 2, take);
		}
		else if (locked(philo->left_fork) && locked(philo->right_fork))
			philo->eat_permission = true;
		else if (philo->number_of_philosophers % 2 == 1 && philo->id == 1 && locked(philo->right_fork))
			philo->eat_permission = true;
		else if (philo->number_of_philosophers % 2 == 1 && philo->id == philo->number_of_philosophers && locked(philo->left_fork))
			philo->eat_permission = true;
		else if (philo->number_of_philosophers == 1)
			ft_fork(philo, 1, take);
	}
	if (ft_end(philo))
	{
		if (!locked(philo->left_fork))
			ft_fork(philo, -1, put);
		if (!locked(philo->right_fork))
			ft_fork(philo, 1, put);
	}
}



void	ft_eat(t_philo *philo)
{
	philo->last_meal_time = get_current_time() - philo->start_time;
	write_status(philo, "is eating", GREEN);
	philo->number_of_meals_eaten++;
	ft_usleep(philo->time_to_eat, philo);
	ft_fork(philo, 2, put); // put the 2 forks right then left
}

void	ft_sleep(t_philo *philo)
{
	write_status(philo, "is sleeping", CYAN);
	ft_usleep(philo->time_to_sleep, philo);
}