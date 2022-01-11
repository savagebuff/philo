/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:54:59 by choney            #+#    #+#             */
/*   Updated: 2021/09/29 19:25:58 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (0);
	return (1);
}

int	check_numeric(char **av, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
	{
		if (is_numeric(av[i]) == 0)
			return (0);
	}
	return (1);
}

void	print(int status, t_philo *p)
{
	long	t;

	sem_wait(p->sems[2]);
	t = timefromstart(p->start_time);
	if (status == 0)
	{
		printf("\x1b[31m%ld %d died\n", t, p->id);
		return ;
	}
	if (status == 1 && !p->is_dead)
		printf("\x1b[34m%ld %d has taken a fork\n", t, p->id);
	if (status == 2 && !p->is_dead)
		printf("\x1b[33m%ld %d is eating\n", t, p->id);
	if (status == 3 && !p->is_dead)
		printf("\x1b[36m%ld %d is sleeping\n", t, p->id);
	if (status == 4 && !p->is_dead)
		printf("\x1b[35m%ld %d is thinking\n", t, p->id);
	sem_post(p->sems[2]);
}
