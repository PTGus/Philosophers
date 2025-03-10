/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:11:12 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/10 15:24:24 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	parsing_err(void)
{
	printf("Usage:\n./philo <number of philos> ");
	printf("<time to die(ms)> <time to eat(ms)> <time to sleep(ms)> ");
	printf("<(optional) number of times each philo eats>\n");
	printf("-Maximum of 200 philos!\n");
	printf("-Minimum of 0 meals each!\n");
	printf("-All values must be positive!\n");
	exit(1);
}

void	init_err(void)
{
	printf("Error initializing variables.\n");
	exit (1);
}

void	malloc_err(void)
{
	printf("Error allocating memory.\n");
	exit (1);
}

void	ft_error(int err_num)
{
	if (err_num == 0)
		parsing_err();
	if (err_num == 1)
		init_err();
	if (err_num == 1)
		malloc_err();
}
