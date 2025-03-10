/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:26:34 by gumendes          #+#    #+#             */
/*   Updated: 2025/03/10 14:55:07 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

long	ft_atol(const char *str)
{
	long	idx;
	long	sign;
	long	sum;

	sign = 1;
	idx = 0;
	sum = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		sum = (sum * 10) + (str[idx] - '0');
		idx++;
	}
	return (sign * sum);
}

int	ft_atoi(const char *str)
{
	int	idx;
	int	sign;
	int	sum;

	sign = 1;
	idx = 0;
	sum = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		sum = (sum * 10) + (str[idx] - '0');
		idx++;
	}
	return (sign * sum);
}
