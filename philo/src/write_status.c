/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:37:37 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/27 21:38:18 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_status(t_philo *philo, char *status, char *color)
{
	size_t	current_time;

	if (ft_end(philo))
		return ;
	pthread_mutex_lock(&philo->data->write_mutex);
	current_time = get_current_time() - philo->start_time;
	printf("%s", color);
	printf("%lu     %d      %s\n", current_time, philo->id, status);
	printf("\033[0m");
	pthread_mutex_unlock(&philo->data->write_mutex);
}
