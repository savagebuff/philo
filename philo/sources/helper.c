/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:50:03 by choney            #+#    #+#             */
/*   Updated: 2021/08/20 23:18:55 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	printstatus(long time, char *message, t_main *philo, char *color)
{
	pthread_mutex_lock(&philo->all->rights_to_write);
	printf("%s%ld Philosofer %d %s\n", color, time, philo->id, message);
	if (!philo->is_dead)
		pthread_mutex_unlock(&philo->all->rights_to_write);
}

int	check_args(int argc, char **argv)
{
	int	n;
	int	i;

	i = 1;
	if (argc < 5)
		return (1);
	while (i < argc)
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] >= 48 && argv[i][n] <= 57)
				n++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	numb;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (neg == -1 || str[i] == '+')
		i++;
	numb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		numb = (numb * 10) + (str[i++] - '0');
	return (numb * neg);
}

int	gettime(int start)
{
	struct timeval	tv;
	long			mls;

	gettimeofday(&tv, NULL);
	mls = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return ((int)mls - start);
}

void	ft_usleep(int in)
{
	time_t	start;
	time_t	end;

	start = gettime(0);
	end = gettime(0) + in;
	while (start < end)
	{
		usleep(10);
		start = gettime(0);
	}
}
