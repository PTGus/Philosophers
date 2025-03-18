/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:15:26 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/17 14:26:08 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (parser(ac, av) != 0)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (init_data(data, av) != 0)
	{
		free(data);
		return (1);
	}
	init_philos(data);
	init_forks(data);
	if (create_threads(data) != 0)
	{
		free_all(data);
		free(data);
		return (1);
	}
	free_all(data);
	free(data);
	return (0);
}
