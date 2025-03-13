/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:28:06 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/13 10:43:12 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	print_message(t_philos *philos, char *message)
{
	size_t	time;

	pthread_mutex_lock(&philos->data->print);
	time = ft_get_time() - philos->data->start_time;
	printf("%lu %i %s\n", time, philos->id, message);
	pthread_mutex_unlock(&philos->data->print);
}

void	eat(t_philos *philos)
{
	pthread_mutex_lock(philos->left_fork);
	pthread_mutex_lock(philos->right_fork);
	print_message(philos, FORK);
	print_message(philos, FORK);
	print_message(philos, EATING);
	philos->last_eat_time = ft_get_time();
	philos->meals_eaten += 1;
	ft_usleep(philos->data->to_eat);
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
}

void	ft_sleep(t_philos *philos)
{
	print_message(philos, SLEEPING);
	ft_usleep(philos->data->to_sleep);
}

void	think(t_philos *philos)
{
	print_message(philos, THINKING);
}

void	died(t_philos *philos)
{
	print_message(philos, DIED);
}
