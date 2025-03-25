/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:39:55 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/25 16:49:20 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

static void	solo_thinker(t_philos *philos);

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
		solo_thinker(philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
	{
		print_message(philo, THINKING);
		ft_usleep(philo->data->to_eat);
	}
	while (philo->philo_stats == ALIVE)
	{
		eat(philo);
		if (philo->data->status != ALIVE)
			return(NULL);
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
	if (ft_get_time() - philo->last_eat_time > (size_t)philo->data->to_die
		&& philo->meals_eaten != philo->data->eat_amount)
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
	return (philo->data->status);
}

/**
 * @brief Iterates through all the philosophers
 *  and checks the simmulations status.
 */
void	monitor(t_data *data)
{
	int	i;

	while (42)
	{
		i = 0;
		while (i < data->philo_amount)
		{
			if (status_checker(&data->philos[i]) == DEAD)
			{
				print_message(&data->philos[i], DIED);
				data->status = DEAD;
				return ;
			}
			i++;
		}
		if (data->status == FULL)
			return ;
	}
}

/**
 * @brief Executes the necessary routine when the number of philosophers is 1.
 */
static void	solo_thinker(t_philos *philos)
{
	print_message(philos, FORK);
	ft_usleep(philos->data->to_die);
}
