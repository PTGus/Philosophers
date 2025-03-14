/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:28:06 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/13 16:43:37 by gumendes         ###   ########.fr       */
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
	if (philos->data->status == DEAD)
		return ;
	if (philos->meals_eaten == philos->data->eat_amount)
		return ;
	pthread_mutex_lock(philos->right_fork);
	pthread_mutex_lock(philos->left_fork);
	print_message(philos, FORK);
	print_message(philos, FORK);
	philos->last_eat_time = ft_get_time();
	print_message(philos, EATING);
	ft_usleep(philos->data->to_eat);
	if (philos->meals_eaten != philos->data->eat_amount)
		philos->meals_eaten++;
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
}

void	ft_sleep(t_philos *philos)
{
	if (philos->data->status == DEAD)
		return ;
	else if (philos->meals_eaten == philos->data->eat_amount)
		return ;
	print_message(philos, SLEEPING);
	ft_usleep(philos->data->to_sleep);
}

void	think(t_philos *philos)
{
	if (philos->data->status == DEAD)
		return ;
	else if (philos->meals_eaten == philos->data->eat_amount)
		return ;
	print_message(philos, THINKING);
}

void	died(t_philos *philos)
{
	print_message(philos, DIED);
}
