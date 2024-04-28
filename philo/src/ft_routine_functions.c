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

void	ft_eat(t_philo *philo)
{
	if (ft_end(philo) || !philo->eat_permission)
		return ;
	while (philo->eat_permission && philo->nbr_forks < 2)
	{
		if (!ft_is_fork_locked(philo->left_fork))
			ft_take_a_fork(philo, philo->left_fork);
		if (!ft_is_fork_locked(philo->right_fork))
			ft_take_a_fork(philo, philo->right_fork);
	}
	philo->last_meal_time = get_current_time() - philo->start_time;
	write_status(philo, "is eating", GREEN);
	ft_usleep(philo->time_to_eat, philo);
	philo->number_of_meals_eaten++;
	philo->eat_permission = false;
	ft_put_a_fork(philo, philo->left_fork);
	ft_put_a_fork(philo, philo->right_fork);
}

void	ft_take_a_fork(t_philo *philo, t_fork *fork)
{
	if (ft_end(philo))
		return ;
	ft_lock_fork(fork);
	philo->nbr_forks++;
	write_status(philo, "has taken a fork", PURPLE);
}

void	ft_put_a_fork(t_philo *philo, t_fork *fork)
{
	ft_unlock_fork(fork);
	philo->nbr_forks--;
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
	if (ft_end(philo))
		return ;
	write_status(philo, "is thinking", YELLOW);
	while ((!philo->eat_permission && philo->nbr_forks < 2))
	{
		if (ft_end(philo))
			break;
		if (!ft_is_fork_locked(philo->left_fork))
		{
			ft_take_a_fork(philo, philo->left_fork);
			break ;
		}
		if (!ft_is_fork_locked(philo->right_fork))
		{
			ft_take_a_fork(philo, philo->right_fork);
			break ;
		}
	}
	if (philo->number_of_philosophers > 1)
		philo->eat_permission = true;
}
