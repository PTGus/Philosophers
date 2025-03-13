/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:15:22 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/13 11:31:40 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	free_all(t_data *data)
{
	int	i;

	// Destroy all fork mutexes
	i = -1;
	while (++i < data->philo_amount)
		pthread_mutex_destroy(&data->forks[i]);

	// Destroy individual mutexes
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->start);

	// Free allocated memory
	free(data->thread_ph);
	free(data->philos);
	free(data->forks);
}
