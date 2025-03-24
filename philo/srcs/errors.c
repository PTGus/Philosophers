/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:11:12 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/24 12:24:22 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief Prints an error message in case of invalid args.
 */
void	parsing_err(void)
{
	printf("Usage:\n./philo <number of philos> ");
	printf("<time to die(ms)> <time to eat(ms)> <time to sleep(ms)> ");
	printf("<(optional) number of times each philo eats>\n");
	printf("-All values must be numeric values only!\n");
	printf("-Maximum of 200 philos!\n");
	printf("-If defined, a minimum of 1 meals each is required!\n");
	printf("-A minimum of 60 ms for any of the times!\n");
	printf("-All values must be positive!\n");
	exit(1);
}

/**
 * @brief Prints an error message in case of initialization error.
 */
void	init_err(void)
{
	printf("Error initializing variables.\n");
	exit (1);
}

/**
 * @brief Prints an error message in case of memory allocation trouble.
 */
void	malloc_err(void)
{
	printf("Error allocating memory.\n");
	exit (1);
}
