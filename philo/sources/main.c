/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:50:12 by choney            #+#    #+#             */
/*   Updated: 2021/08/20 23:44:06 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_all *all, int i)
{
	if (gettime(all->input.start) - all->philosofers[i].last_eat
		 > all->input.time_to_die && all->philosofers[i].stop != 1)
	{
		all->philosofers[i].is_dead = 1;
		printstatus(gettime(all->input.start), "die", &all->philosofers[i],
			 "\x1b[31m");
		return (1);
	}
	return (0);
}

void	*check_hunger(void *all)
{
	t_all	*head;
	int		philo_is_full;
	int		i;

	head = (t_all *)all;
	while (1)
	{
		i = 0;
		philo_is_full = 0;
		while (i < head->input.num_of_philo)
		{
			if (head->philosofers[i].count_eat >= head->input.num_of_eat
				&& head->input.num_of_eat != -1)
			{
				philo_is_full++;
				head->philosofers[i].stop = 1;
			}
			if (check_death(all, i))
				return (0);
			i++;
		}
		if (philo_is_full == head->input.num_of_philo)
			return (0);
	}
	return (0);
}

void	*actions(void *philos)
{
	t_main	*head;

	head = (t_main *)philos;
	while (1)
	{
		ft_take_fork(head);
		ft_eat(head);
		head->count_eat++;
		if (head->count_eat == head->params.num_of_eat
			 && head->params.num_of_eat != -1)
		{
			return (0);
		}
		ft_sleeping(head);
		ft_thinking(head);
	}
	return (0);
}

void	ft_philo(t_all *all)
{
	int			i;
	pthread_t	thread;

	i = 0;
	pthread_create(&thread, NULL, check_hunger, all);
	while (i < all->input.num_of_philo)
	{
		pthread_create(&all->philosofers->thread, NULL,
			 actions, all->philosofers + i);
		usleep(50);
		i++;
	}
	pthread_join(thread, NULL);
	free_all(all);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (check_args(argc, argv) == 0)
	{
		all = (struct s_all *)malloc(sizeof(t_all));
		if (all == 0)
			return (0);
		pthread_mutex_init(&all->rights_to_write, NULL);
		if (init_input(argc, argv, all) == 0)
		{
			all->input.start = gettime(0);
			init_philosofers(all->input.num_of_philo, all);
			init_forks(all);
			give_forks(all);
			ft_philo(all);
		}
	}
	else
	{
		printf("Invalid input\n");
		return (0);
	}
}
