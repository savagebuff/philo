/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:50:08 by choney            #+#    #+#             */
/*   Updated: 2021/08/20 23:18:38 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_input(int argc, char **argv, t_all *all)
{
	all->input.num_of_philo = ft_atoi(argv[1]);
	all->input.time_to_die = ft_atoi(argv[2]);
	all->input.time_to_eat = ft_atoi(argv[3]);
	all->input.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->input.num_of_eat = ft_atoi(argv[5]);
	else
		all->input.num_of_eat = -1;
	return (0);
}

void	init_philosofers(int num_of_philo, t_all *all)
{
	int		i;

	i = 0;
	all->philosofers = (struct s_main *)
		malloc(sizeof(t_main) * all->input.num_of_philo);
	if (all->philosofers == 0)
		return ;
	while (i < num_of_philo)
	{
		all->philosofers[i].stop = 0;
		all->philosofers[i].count_eat = 0;
		all->philosofers[i].is_dead = 0;
		all->philosofers[i].all = all;
		all->philosofers[i].last_eat = 0;
		all->philosofers[i].id = i + 1;
		all->philosofers[i].params = all->input;
		i++;
	}
}

void	init_forks(t_all *all)
{
	int	i;

	i = 0;
	all->forks = malloc(sizeof(pthread_mutex_t) * all->input.num_of_philo);
	if (all->forks == 0)
		return ;
	while (i < all->input.num_of_philo)
	{
		pthread_mutex_init(&all->forks[i], NULL);
		i++;
	}
}

void	give_forks(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->input.num_of_philo)
	{
		if (i == all->input.num_of_philo - 1)
		{
			all->philosofers[i].left_fork = &all->forks[i];
			all->philosofers[i].right_fork = &all->forks[0];
		}
		else
		{
			all->philosofers[i].left_fork = &all->forks[i];
			all->philosofers[i].right_fork = &all->forks[i + 1];
		}
		i++;
	}
}
