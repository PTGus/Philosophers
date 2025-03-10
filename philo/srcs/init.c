/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:58:13 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/10 17:16:04 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

/**
 * @brief Allocates all the memory necessary.
 * @return 0 if successful
 *
 * Any non 0 value if unsuccessful
 */
int	mallocinator(t_data **data, int philo_ammount)
{
	(*data)->thread_ph = malloc(sizeof(pthread_t) * philo_ammount);
	if (!(*data)->thread_ph)
		return (1);
	(*data)->philos = malloc(sizeof(t_philos) * philo_ammount);
	if (!(*data)->philos)
	{
		free((*data)->thread_ph);
		return (2);
	}
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * philo_ammount);
	if (!(*data)->forks)
	{
		free((*data)->thread_ph);
		free((*data)->philos);
		return (3);
	}
	return (0);
}

void	init_forks(t_data **data)
{
	int			i;
	t_philos	*philo;

	i = -1;
	philo = (*data)->philos;
	while (i < (*data)->philo_amount)
		pthread_mutex_init(&(*data)->forks[i], NULL);
	i = 0;
	philo[0].right_fork = &(*data)->forks[0];
	if ((*data)->philo_amount == 1)
		return ;
	
}

void	init_philos(t_data **data)
{
	int		i;
	t_philos	*philo;

	i = 0;
	philo = (*data)->philos;
	while (i < (*data)->philo_amount)
	{
		philo[i].data = *data;
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_eat_time = 0;
		i++;
	}
}

/**
 * @brief Initializes all the variables to their required values
 * @return 0 if successful
 *
 * Any non 0 value if unsuccessful
 */
int	init_data(t_data **data, char **av)
{
	(*data)->philo_amount = ft_atoi(av[1]);
	(*data)->to_die = ft_atoi(av[2]);
	(*data)->to_eat = ft_atoi(av[3]);
	(*data)->to_sleep = ft_atoi(av[4]);
	(*data)->eat_amount = -1;
	if (av[5])
		(*data)->eat_amount = ft_atoi(av[5]);
	(*data)->is_death = ALIVE;
	(*data)->philos_full = 0;
	if (gettimeofday(&(*data)->start, NULL) == -1)
		return (1);
	if (pthread_mutex_init((*data)->forks, NULL) != 0)
		return (2);
	if (mallocinator(data, (*data)->philo_amount) != 0)
		return (3);
	return (0);
}
