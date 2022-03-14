/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:17:19 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/02 16:17:21 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		if (i == 0)
			data->philo[i].right_fork = &data->forks[data->nb_of_philo - 1];
		else
			data->philo[i].right_fork = &data->forks[i - 1];
		i++;
	}
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].state_dead = false;
		data->philo[i].data = data;
		data->philo[i].last_diner = ft_time();
		data->philo[i].one_must_eat = data->nb_of_time_must_eat;
		data->philo[i].left_fork = &data->forks[i];
		pthread_mutex_init(&data->philo[i].lock, NULL);
		i++;
	}
	ft_init_fork(data);
}

void	ft_init_data_av(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->death = 0;
	if (ac == 6)
		data->nb_of_time_must_eat = ft_atoi(av[5]);
	else
		data->nb_of_time_must_eat = -1;
}

void	ft_init_data(t_data *data, int ac, char **av)
{
	ft_init_data_av(data, ac, av);
	data->time_starter = ft_time();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->check_death, NULL);
	data->philo = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!data->philo)
		return ;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->forks)
		return ;
}
