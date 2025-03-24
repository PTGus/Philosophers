/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:39:55 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/24 12:25:22 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief The routine in which the philosophers will
 *  eat, sleep and think untill the simmulation ends.
 */
void	*routine(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	philo->last_eat_time = philo->data->start_time;
	if (philo->data->philo_amount == 1)
	{
		print_message(philo, FORK);
		ft_usleep(philo->data->to_die);
		return (NULL);
	}
	if (philo->id % 2 != 0)
	{
		print_message(philo, THINKING);
		ft_usleep(philo->data->to_eat);
	}
	while (philo->data->status == ALIVE)
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}

/**
 * @brief Checks whether a philosophers time after the last meal
 *  exceeds the time to die, if the philosopher is full and if all
 *  the philosophers are full.
 */
int	status_checker(t_philos *philo)
{
	int	i;

	i = 0;
	if (philo->philo_stats != FULL)
	{
		if (ft_get_time() - philo->last_eat_time > (size_t)philo->data->to_die)
		{
			philo->data->status = DEAD;
			return (DEAD);
		}
		else if (philo->meals_eaten == philo->data->eat_amount && \
			philo->philo_stats == ALIVE)
		{
			philo->data->philos_full++;
			philo->philo_stats = FULL;
		}
		if (philo->data->philos_full == philo->data->philo_amount)
			philo->data->status = FULL;
		i = philo->data->status;
	}
	else
		return (i);
	return (i);
}

/**
 * @brief Iterates through all the philosophers
 *  and checks the simmulations status.
 */
void	monitor(t_data *data)
{
	int		i;

	i = 0;
	while (42)
	{
		if (status_checker(&data->philos[i]) != ALIVE)
			break ;
		i++;
		if (i == data->philo_amount)
			i = 0;
	}
	if (data->status == DEAD)
		died(&data->philos[i]);
}
