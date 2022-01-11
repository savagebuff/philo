/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:11:12 by choney            #+#    #+#             */
/*   Updated: 2021/09/29 19:11:56 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long	timestamp(void)
{
	struct timeval	t;
	long			rt;

	gettimeofday(&t, 0);
	rt = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (rt);
}

void	ft_usleep(long dt, t_philo *t)
{
	long	needed_time;

	needed_time = timestamp() + dt / 1000;
	while (timestamp() < needed_time)
	{
		if (t->is_dead)
			return ;
		usleep(500);
	}
}

long	timefromstart(long time)
{
	return ((timestamp() - time));
}
