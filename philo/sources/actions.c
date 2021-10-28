/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:30:31 by choney            #+#    #+#             */
/*   Updated: 2021/08/20 23:36:56 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_take_fork(t_main *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printstatus(gettime(philo->params.start), "take left fork",
		 philo, "\x1b[34m");
	pthread_mutex_lock(philo->right_fork);
	printstatus(gettime(philo->params.start), "take right fork",
		 philo, "\x1b[34m");
}

void	ft_eat(t_main *philo)
{
	printstatus(gettime(philo->params.start), "eating", philo, "\x1b[33m");
	philo->last_eat = gettime(philo->params.start);
	ft_usleep(philo->params.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleeping(t_main *philo)
{
	printstatus(gettime(philo->params.start), "sleeping", philo, "\x1b[36m");
	ft_usleep(philo->params.time_to_sleep);
}

void	ft_thinking(t_main *philo)
{
	printstatus(gettime(philo->params.start), "thinking", philo, "\x1b[35m");
}

void	free_all(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->input.num_of_philo)
		pthread_mutex_destroy(&all->forks[i]);
	free(all->forks);
	free(all->philosofers);
	pthread_mutex_destroy(&all->rights_to_write);
}
