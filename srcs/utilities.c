/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 01:53:18 by amonteli          #+#    #+#             */
/*   Updated: 2021/12/03 19:50:06 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_integer(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
			return (0);
		index++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		neg;
	long	number;

	neg = 1;
	i = 0;
	number = 0;
	if (!is_integer(str))
		return (0);
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * neg);
}

int	errors(char *error)
{
	printf("Error: {%s}\n", error);
	return (0);
}

unsigned long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	unsufissent_forks(t_philo *philo)
{
	usleep(philo->global->time_to_die * 1000);
	ps_log(philo, A_DIE);
	exit(0);
}
