/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:39:55 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/13 16:48:24 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	*routine(void *info)
{
	t_philos	*philos;

	philos = (t_philos *)info;
	pthread_mutex_lock(&philos->data->start);
	pthread_mutex_unlock(&philos->data->start);
	philos->last_eat_time = philos->data->start_time;
	if (philos->data->philo_amount == 1)
	{
		print_message(philos, FORK);
		ft_usleep(philos->data->to_die);
		return (NULL);
	}
	if (philos->id % 2 != 0)
	{
		print_message(philos, THINKING);
		ft_usleep(philos->data->to_eat);
	}
	while (philos->data->status == ALIVE)
	{
		eat(philos);
		ft_sleep(philos);
		think(philos);
	}
	return (NULL);
}

int	status_checker(t_philos *philo)
{
	int	i;

	i = 0;
	if (ft_get_time() - philo->last_eat_time > (size_t)philo->data->to_die)
	{
		philo->data->status = DEAD;
		philo->philo_stats = DEAD;
		return (DEAD);
	}
	else if (philo->meals_eaten == philo->data->eat_amount && \
	philo->philo_stats != FULL)
	{
		philo->data->philos_full++;
		philo->philo_stats = FULL;
	}
	if (philo->data->philos_full == philo->data->philo_amount)
		philo->data->status = FULL;
	i = philo->data->status;
	return (i);
}

void	monitor(t_data *data)
{
	int		i;

	i = 0;
	while (42)
	{
		if (status_checker(&data->philos[i]) != ALIVE)
			break ;
		if (data->status == FULL)
			break ;
		i++;
		if (i == data->philo_amount)
			i = 0;
	}
	if (data->status == DEAD)
	{
		print_message(&data->philos[i], DIED);
		free_all(data);
		exit (0);
	}
}
