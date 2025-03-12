/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:42 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/12 12:16:37 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

size_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

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
