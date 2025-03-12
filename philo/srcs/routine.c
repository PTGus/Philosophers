/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:39:55 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/12 17:05:16 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	*routine(void *info)
{
	t_philos	*philos;
	size_t		time;
	int			i;

	time = 0;
	philos = (t_philos *)info;
	i = 0;
	pthread_mutex_lock(&philos->data->start);
	pthread_mutex_unlock(&philos->data->start);
	philos->last_eat_time = philos->data->start_time;
	while (i != philos->data->eat_amount)
	{
		if (philos->data->status == DEAD)
			break ;
		eat(philos);
		ft_sleep(philos);
		think(philos);
		i++;
	}
	return (NULL);
}

int	status_checker(t_philos *philo)
{
	size_t	i;
	size_t	time;

	i = 0;
	time = ft_get_time();
	if (time - philo->last_eat_time > (size_t)philo->data->to_die)
	{
		philo->data->status = DEAD;
		philo->philo_stats = DEAD;
		died(philo);
		return (DEAD);
	}
	else if (philo->meals_eaten == philo->data->eat_amount)
	{
		philo->philo_stats = FULL;
		return (ALIVE);
	}
	return (ALIVE);
}

void	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == data->philo_amount)
			i = 0;
		if (status_checker(&data->philos[i]) == DEAD)
			return ;
		if (data->philos[i].philo_stats == DEAD)
			return ;
		if (data->philos[i].meals_eaten == FULL)
			data->philos_full++;
		if (data->philos_full == data->philo_amount)
			return ;
		i++;
	}
}
