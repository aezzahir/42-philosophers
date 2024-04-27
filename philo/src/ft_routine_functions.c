/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:17:05 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/27 21:23:38 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_philo *philo)
{
	if (ft_end(philo) || philo->time_to_eat < 1)
		return ;
	if (philo->eat_permission)
	{
		if (!ft_is_fork_locked(philo->left_fork))
			ft_take_a_fork(philo, philo->left_fork);
		if (!ft_is_fork_locked(philo->right_fork))
			ft_take_a_fork(philo, philo->right_fork);
	}
	else
		return ;
	philo->last_meal_time = get_current_time() - philo->start_time;
	write_status(philo, "is eating", GREEN);
	ft_usleep(philo->time_to_eat, philo);
	philo->number_of_meals_eaten++;
	ft_unlockt_fork(philo->left_fork);
	ft_unlockt_fork(philo->right_fork);
	philo->eat_permission = false;
}

void	ft_take_a_fork(t_philo *philo, t_fork *fork)
{
	if (ft_end(philo))
		return ;
	ft_lock_fork(fork);
	write_status(philo, "has taken a fork", PURPLE);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_end(philo) || philo->time_to_sleep < 1)
		return ;
	write_status(philo, "is sleeping", CYAN);
	ft_usleep(philo->time_to_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	int nbr_of_forks;

	nbr_of_forks = 0;
	if (ft_end(philo))
		return ;
	write_status(philo, "is thinking", YELLOW);
	while (!ft_check_eating_permission(philo) && nbr_of_forks < 2)
	{
		if (ft_end(philo))
			return ;
		if (!ft_is_fork_locked(philo->left_fork))
		{
			ft_take_a_fork(philo, philo->left_fork);
			nbr_of_forks++;
		}
		if (!ft_is_fork_locked(philo->right_fork))
		{
			ft_take_a_fork(philo, philo->right_fork);
			nbr_of_forks++;
		}
	}
	philo->eat_permission = true;
}
