/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:15:22 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/24 10:16:55 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief Destroys the mutexes and frees all allocated memmory.
 */
void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_amount)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->start);
	free(data->thread_ph);
	free(data->philos);
	free(data->forks);
}
