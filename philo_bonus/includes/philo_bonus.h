/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:37:35 by choney            #+#    #+#             */
/*   Updated: 2021/09/29 19:47:48 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <signal.h>
# include <string.h>

typedef struct s_philo
{
	pthread_t	monitor;
	pthread_t	eated_check;
	sem_t		**is_eated;
	sem_t		**sems;
	pid_t		*pids;
	int			id;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			eat_count;
	int			eat_need;
	int			philo_count;
	int			is_dead;
	long		start_time;
	long		start_eat;
}			t_philo;

// parser.c

t_philo	*getPhilo(int argc, char **argv);
int		checkErrors(int argc, char **argv, t_philo **t);
int		checkInput(char **argv, int argc, t_philo *rt);
void	create_sems(t_philo *rt);
void	check_sem_errors(t_philo *t);

// utils.c

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		is_numeric(char *str);
int		check_numeric(char **av, int ac);
void	print(int status, t_philo *p);

// exit.c

void	freeExit(t_philo *t, int i);
void	freeAll(t_philo *t, int j);
void	printExit(char *str, int c);

// main.c

void	*isAllEat(void *ph);
void	startProcess(t_philo *t);
void	startEatThread(t_philo *t);
int		createThread(t_philo *t);

// actions.c

void	*monitoring(void *ph);
int		isEat(t_philo *t);
int		isDead(t_philo *p);
int		takeForks(t_philo *t);
int		eat(t_philo *t);

// time.c

long	timestamp(void);
long	timefromstart(long time);
void	ft_usleep(long dt, t_philo *t);

#endif