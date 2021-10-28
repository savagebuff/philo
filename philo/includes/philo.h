#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_all	t_all;

typedef struct s_input
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	int				start;
}				t_input;

typedef struct s_main
{
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_all				*all;
	int					is_dead;
	int					last_eat;
	int					count_eat;
	int					id;
	int					stop;
	t_input				params;
}				t_main;

typedef struct s_all
{
	t_main				*philosofers;
	pthread_mutex_t		*forks;
	t_input				input;
	pthread_mutex_t		rights_to_write;
}				t_all;

//initialization.c

int		init_input(int argc, char **argv, t_all *all);
void	init_philosofers(int num_of_philo, t_all *all);
void	init_forks(t_all *all);
void	give_forks(t_all *all);

//helper.c

void	printstatus(long time, char *message, t_main *philo, char *color);
void	ft_usleep(int in);
int		check_args(int argc, char **argv);
int		ft_atoi(const char *str);
int		gettime(int start);

//actions.c

void	ft_take_fork(t_main *philo);
void	ft_eat(t_main *philo);
void	ft_sleeping(t_main *philo);
void	ft_thinking(t_main *philo);
void	free_all(t_all *all);

#endif