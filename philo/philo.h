/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:36:44 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/08 15:36:46 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/***************** LIBRAIRIES *****************/
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "unistd.h"
# include "pthread.h"
# include <sys/time.h>

/********************MACROS*******************/
# ifndef FAILURE
#  define FAILURE 1
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

/******STATES*******/
# ifndef EATING
#  define EATING 2
# endif

# ifndef SLEEPING
#  define SLEEPING 3
# endif

# ifndef THINKING
#  define THINKING 4
# endif

/******COLORS*******/
# ifndef YELLOW
#  define YELLOW "\033[0;33m"
# endif

# ifndef GREEN
#  define GREEN "\033[0;32m"
# endif

# ifndef PURPLE
#  define PURPLE "\033[0;35m"
# endif

# ifndef BLUE
#  define BLUE "\033[0;36m"
# endif

/**************** TYPE BOOLEEN ****************/
typedef enum Bool
{
	false,
	true
}	t_Bool;

/***************** STRUCTURES *****************/
typedef struct s_data
{	
	int				nb_of_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				nb_of_time_must_eat;
	long int		time_starter;
	int				death;
	pthread_t		checker;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	check_death;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{	
	t_data				*data;
	int					id;
	int					one_must_eat;
	t_Bool				state_dead;
	pthread_t			philo_th;
	long int			last_diner;
	pthread_mutex_t		lock;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
}	t_philo;

/************ FONCTIONS PROTOTYPES ************/
/* UTILS */
long int	ft_time(void);
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_str_isdigit(char *str);
void		ft_usleep(long int time);
void		ft_print(t_philo *philo, char *str, char *COLOR);
void		ft_free(t_data *data);
/* ACTIONS */
int			*routine(t_philo *philo);
void		ft_eating(t_philo *philo,
				pthread_mutex_t *fork_a, pthread_mutex_t *fork_b);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
int			ft_philo_death(t_philo *philo);
int			ft_checker(t_data *data);
/* INIT */
void		ft_init_data(t_data *data, int ac, char **av);
void		ft_init_philo(t_data *data);
void		ft_init_fork(t_data *data);
/* THREADS */
int			ft_phtread_join(t_data *data);
int			ft_create_thread(t_data *data);

#endif
