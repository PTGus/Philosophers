/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:19:30 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/12 16:14:40 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

/*
 //====================================================\\
||                     LIBRARIES                        ||
 \\====================================================//
*/

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>
# include <limits.h>

/*
 //====================================================\\
||                     MACROS                           ||
 \\====================================================//
*/

# define ALIVE 0
# define DEAD 1
# define FULL 2
# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

/*
 //====================================================\\
||                     STRUCTURES                       ||
 \\====================================================//
*/

typedef struct s_data	t_data;

typedef struct s_philos
{
	int				id;
	int				meals_eaten;
	int				philo_stats;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	size_t			last_eat_time;
	struct s_data	*data;
}	t_philos;

typedef struct s_data
{
	int				philo_amount;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				eat_amount;
	int				philos_full;
	int				status;
	size_t			start_time;
	t_philos		*philos;
	pthread_t		*thread_ph;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	start;
}	t_data;

/*
 //====================================================\\
||                     DECLARATIONS                     ||
 \\====================================================//
*/

// actions //
void	print_message(t_philos *philos, char *message);
void	eat(t_philos *philos);
void	ft_sleep(t_philos *philos);
void	think(t_philos *philos);
void	died(t_philos *philos);

// errors //
void	parsing_err(void);
void	init_err(void);
void	malloc_err(void);
void	ft_error(int err_num);

// init //
int		mallocinator(t_data *data, int philo_ammount);
void	init_forks(t_data *data);
void	init_philos(t_data *data);
int		init_data(t_data *data, char **av);
int		create_threads(t_data *data);

// main //
int		main(int ac, char **av);

// parsing //
int		validator(char **args);
int		parser(int ac, char **av);

// routine //
void	*routine(void *info);
int		status_checker(t_philos *philo);
void	monitor(t_data *data);

// utils //
long	ft_atol(const char *str);
int		ft_atoi(const char *str);

// time //
size_t	ft_get_time(void);
void	ft_usleep(size_t sleeptime);

#endif
