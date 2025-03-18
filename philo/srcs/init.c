/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:58:13 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/18 16:16:02 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief Allocates all the memory necessary.
 * @return 0 if successful.
 *
 * Any non 0 value if unsuccessful.
 */
int	mallocinator(t_data *data, int philo_ammount)
{
	data->thread_ph = malloc(sizeof(pthread_t) * philo_ammount);
	if (!data->thread_ph)
		return (1);
	data->philos = malloc(sizeof(t_philos) * philo_ammount);
	if (!data->philos)
	{
		free(data->thread_ph);
		return (2);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * philo_ammount);
	if (!data->forks)
	{
		free(data->thread_ph);
		free(data->philos);
		return (3);
	}
	return (0);
}

/**
 * @brief Initializes all the mutexs and assigns which
 *  fork each philosopher should try to grab.
 */
void	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_amount)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philos[0].right_fork = &data->forks[0];
	if (data->philo_amount == 1)
		return ;
	data->philos[0].left_fork = &data->forks[data->philo_amount - 1];
	i = 0;
	while (++i < data->philo_amount)
	{
		if (data->philos[i].id % 2 == 0 && data->philo_amount != 2)
		{
			data->philos[i].right_fork = &data->forks[i];
			data->philos[i].left_fork = &data->forks[i - 1];
		}
		else
		{
			data->philos[i].right_fork = &data->forks[i - 1];
			data->philos[i].left_fork = &data->forks[i];
		}
	}
}

/**
 * @brief Initializes all the variables to their required
 *  values for the philos sub struct.
 */
void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_eat_time = 0;
		data->philos[i].philo_stats = ALIVE;
		i++;
	}
}

/**
 * @brief Initializes all the variables
 * to their required values for the main data struct.
 * @return 0 if successful.
 *
 * Any non 0 value if unsuccessful.
 */
int	init_data(t_data *data, char **av)
{
	data->philo_amount = ft_atoi(av[1]);
	data->to_die = ft_atoi(av[2]);
	data->to_eat = ft_atoi(av[3]);
	data->to_sleep = ft_atoi(av[4]);
	data->eat_amount = -1;
	if (av[5] != NULL)
	{
		if (av[5][0] != '\0')
			data->eat_amount = ft_atoi(av[5]);
	}
	data->philos_full = 0;
	data->status = ALIVE;
	data->start_time = ft_get_time();
	if (mallocinator(data, data->philo_amount) != 0)
		return (1);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (2);
	return (0);
}

/**
 * @brief Creates all the threads.
 */
int	create_threads(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->start);
	while (++i < data->philo_amount)
	{
		if (pthread_create(&data->thread_ph[i], NULL, &routine, \
		&data->philos[i]) != 0)
			return (1);
	}
	data->start_time = ft_get_time();
	pthread_mutex_unlock(&data->start);
	ft_usleep(data->to_die - 10);
	monitor(data);
	i = -1;
	while (++i < data->philo_amount)
	{
		if (pthread_join(data->thread_ph[i], NULL) != 0)
			return (1);
	}
	return (0);
}
