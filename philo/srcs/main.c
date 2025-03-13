/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:15:26 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/13 11:30:47 by gumendes         ###   ########.fr       */
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
		return (1);
	init_philos(data);
	init_forks(data);
	create_threads(data);
	free_all(data);
	return (0);
}
