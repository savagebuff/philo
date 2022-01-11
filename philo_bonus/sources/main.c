/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:44:03 by choney            #+#    #+#             */
/*   Updated: 2021/09/29 19:48:38 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	createThread(t_philo *t)
{
	int	er;

	er = pthread_create(&(t->monitor),
			NULL, monitoring, (void *)t);
	if (er != 0)
		return (0);
	return (1);
}

void	startProcess(t_philo *t)
{
	t->start_eat = timestamp();
	if (!(createThread(t)))
		exit (0);
	pthread_detach(t->monitor);
	while (1)
	{
		if (t->id % 2 == 0)
			ft_usleep(200, t);
		takeForks(t);
		eat(t);
		print(3, t);
		ft_usleep(t->sleep_time * 1000, t);
		print(4, t);
	}
}

void	*isAllEat(void *ph)
{
	t_philo	*t;
	int		i;

	t = (t_philo *)ph;
	i = -1;
	while (++i < t->philo_count && t->is_dead == 0)
		sem_wait(t->is_eated[i]);
	sem_post(t->sems[1]);
	t->is_dead = 1;
	return (NULL);
}

void	startEatThread(t_philo *t)
{
	int	er;

	if (t->eat_need > 0)
	{
		er = pthread_create(&(t->eated_check),
				NULL, isAllEat, (void *)t);
		if (er < 0)
			freeExit(t, t->philo_count);
		pthread_detach(t->eated_check);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*t;

	t = NULL;
	checkErrors(argc, argv, &t);
	i = -1;
	t->start_time = timestamp();
	while (++i < t->philo_count)
	{
		t->id = i + 1;
		t->pids[i] = fork();
		if (t->pids[i] == 0)
			startProcess(t);
		else if (t->pids[i] < 0)
			freeExit(t, i);
	}
	startEatThread(t);
	sem_wait(t->sems[1]);
	t->is_dead = 1;
	freeAll(t, t->philo_count);
	return (0);
}
