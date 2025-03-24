/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:28:06 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/24 11:27:26 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief Locks the mutexes in order for the threads to not
 *  cause race conditions in the printf buffer and prints a message.
 */
void	print_message(t_philos *philos, char *message)
{
	size_t	time;

	pthread_mutex_lock(&philos->data->print);
	time = ft_get_time() - philos->data->start_time;
	printf("%lu %i %s\n", time, philos->id, message);
	pthread_mutex_unlock(&philos->data->print);
}

/**
 * @brief Locks the required forks, prints the required messages
 *  and makes the thread wait while the time to eat doesn't end.
 */
void	eat(t_philos *philos)
{
	if (philos->data->status != ALIVE || philos->philo_stats != ALIVE
		|| philos->meals_eaten == philos->data->eat_amount)
		return ;
	pthread_mutex_lock(philos->right_fork);
	pthread_mutex_lock(philos->left_fork);
	if (philos->data->status != ALIVE || philos->philo_stats != ALIVE
		|| philos->meals_eaten == philos->data->eat_amount)
	{
		pthread_mutex_unlock(philos->left_fork);
		pthread_mutex_unlock(philos->right_fork);
		return ;
	}
	print_message(philos, FORK);
	print_message(philos, FORK);
	philos->last_eat_time = ft_get_time();
	print_message(philos, EATING);
	ft_usleep(philos->data->to_eat);
	if (philos->meals_eaten != philos->data->eat_amount)
		philos->meals_eaten++;
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
	return ;
}

/**
 * @brief Prints the sleep message and puts the philosopher to "sleep".
 */
void	ft_sleep(t_philos *philos)
{
	if (philos->data->status == DEAD || philos->data->status == FULL)
		return ;
	else if (philos->meals_eaten == philos->data->eat_amount)
		return ;
	print_message(philos, SLEEPING);
	ft_usleep(philos->data->to_sleep);
}

/**
 * @brief Prints the think message.
 */
void	think(t_philos *philos)
{
	if (philos->data->status == DEAD || philos->data->status == FULL)
		return ;
	else if (philos->meals_eaten == philos->data->eat_amount)
		return ;
	print_message(philos, THINKING);
}

/**
 * @brief Prints the dead message.
 */
void	died(t_philos *philos)
{
	print_message(philos, DIED);
}
