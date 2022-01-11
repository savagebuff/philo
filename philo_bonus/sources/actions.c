/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:30:06 by choney            #+#    #+#             */
/*   Updated: 2021/09/29 19:49:16 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*monitoring(void *ph)
{
	t_philo	*t;

	t = (t_philo *) ph;
	while (1)
	{
		if (isEat(t) && t->eat_count >= 0)
			sem_post(t->is_eated[t->id - 1]);
		if (isDead(t))
		{
			sem_post(t->sems[1]);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

int	isDead(t_philo *p)
{
	if (p->start_eat + p->die_time < timestamp())
	{
		print(0, p);
		return (1);
	}
	return (0);
}

int	isEat(t_philo *t)
{
	if ((t->eat_count < t->eat_need))
		return (0);
	return (1);
}

int	takeForks(t_philo *t)
{
	if (t->is_dead == 1)
		return (0);
	sem_wait(t->sems[0]);
	print(1, t);
	sem_wait(t->sems[0]);
	print(1, t);
	return (1);
}

int	eat(t_philo *t)
{
	if (t->is_dead)
		return (0);
	t->start_eat = timestamp();
	print(2, t);
	ft_usleep(t->eat_time * 1000, t);
	sem_post(t->sems[0]);
	sem_post(t->sems[0]);
	t->eat_count += 1;
	return (1);
}
