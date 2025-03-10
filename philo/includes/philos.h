/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:19:30 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/10 17:08:45 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define ALIVE 0
# define DEATH 1

typedef struct s_data;

typedef struct s_philos
{
	int				id;
	int				meals_eaten;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	size_t			last_eat_time;
	struct s_data 	*data;
}	t_philos;

typedef struct s_data
{
	int				philo_amount;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				eat_amount;
	int				philos_full;
	int				is_death;
	t_philos		*philos;
	struct timeval	start;
	pthread_t		*thread_ph;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	status;
}	t_data;

// errors //
void	parsing_err(void);
void	init_err(void);
void	malloc_err(void);
void	ft_error(int err_num);

// init //
int		mallocinator(t_data **data, int philo_ammount);
void	init_philos(t_data **data);
int		init_data(t_data **data, char **av);

// main //
int		main(int ac, char **av);

// parsing //
int		validator(char **args);
int		parser(int ac, char **av);

// utils //
long	ft_atol(const char *str);
int		ft_atoi(const char *str);

#endif
