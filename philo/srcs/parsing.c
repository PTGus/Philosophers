/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:15:31 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/06 14:16:24 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

int	validator(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parser(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("Invalid number of arguments!\n"));
	if (validator(av) == 1)
		parsing_err();
	if (ft_atol(av[2]) < INT_MIN || ft_atol(av[3]) < INT_MIN || ft_atol(av[4]) < INT_MIN)
		parsing_err();
	if (ft_atol(av[2]) > INT_MAX || ft_atol(av[3]) > INT_MAX || ft_atol(av[4]) > INT_MAX)
		parsing_err();
	if (ft_atol(av[1]) > 200)
		parsing_err();
	if (ft_atol(av[2]) < 60 || ft_atol(av[3]) < 60 || ft_atol(av[4]) < 60)
		parsing_err();
	if (ft_atol(av[1]) < 1)
		parsing_err();
	if (av[5])
	{
		if (ft_atol(av[5]) < 1)
			parsing_err();
	}
	return (0);
}
