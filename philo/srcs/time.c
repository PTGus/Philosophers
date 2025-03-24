/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:42 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/24 10:25:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief Gets the current time in milliseconds.
 */
size_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * @brief A more precise version of the usleep
 *  function utilized in order to avoid delay.
 */
void	ft_usleep(size_t sleeptime)
{
	size_t	starting_time;
	size_t	remaining_time;

	starting_time = ft_get_time();
	remaining_time = sleeptime - (ft_get_time() - starting_time);
	while (remaining_time > 0)
	{
		if (remaining_time > 500)
			usleep(500);
		else
			usleep(remaining_time);
		remaining_time = sleeptime - (ft_get_time() - starting_time);
	}
}
