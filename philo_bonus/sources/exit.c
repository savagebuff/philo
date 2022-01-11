/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:03:28 by choney            #+#    #+#             */
/*   Updated: 2021/09/29 19:06:28 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	freeExit(t_philo *t, int i)
{
	freeAll(t, i);
	printExit("Error", 1);
}

void	freeAll(t_philo *t, int j)
{
	int		i;
	char	c[4];

	i = -1;
	while (++i < t->philo_count)
		kill(t->pids[i], 9);
	i = -1;
	memset(c, '1', 3);
	c[3] = 0;
	while (++i < j)
	{
		c[3] = c[3] + 1;
		sem_unlink(c);
	}
	sem_unlink("PHIL_FORKS");
	sem_unlink("PHIL_DEATH");
	sem_unlink("PHIL_PRINT");
	free(t->sems);
	free(t->pids);
	free(t->is_eated);
	free(t);
}

void	printExit(char *str, int c)
{
	printf("%s\n", str);
	exit (c);
}
