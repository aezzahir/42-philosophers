/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:17:15 by aezzahir          #+#    #+#             */
/*   Updated: 2024/04/27 22:20:35 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_arguments
{
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
	bool			someone_died;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	key;
	bool			is_locked;
}	t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_data		*data;
	bool		died;
	bool		eat_permission;
	int			number_of_philosophers;
	size_t		start_time;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		death_time;
	int			number_of_times_each_philosopher_must_eat;
	int			number_of_meals_eaten;
	int			last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philo;

t_fork	*ft_forks(int number_of_philosophers);
void	ft_init_fork(t_fork *fork);
void	ft_lock_fork(t_fork *fork);
void	ft_unlockt_fork(t_fork *fork);
void	ft_destroy_fork(t_fork *fork);
bool	ft_is_fork_locked(t_fork *fork);
void	*philo_routine(void *philo);
bool	ft_parse_arguments(int argc, char *argv[], t_data *data);
size_t	ft_atoi(const char *str);
void	ft_init_philosopher(t_philo *philosopers, t_data *data, t_fork *forks);
void	ft_run_simulation(t_philo *philosophers, t_data *data);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_take_a_fork(t_philo *philo, t_fork *fork);
bool	ft_check_eating_permission(t_philo *philo);
bool	ft_check_death(t_philo *philo);
bool	ft_philo_is_full(t_philo *philo);
bool	ft_end(t_philo *philo);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds, t_philo *philo);
void	write_status(t_philo *philo, char *status, char *color);
void	ft_cleanup(t_philo *philosophers, t_data *data, t_fork *forks);

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

#endif
