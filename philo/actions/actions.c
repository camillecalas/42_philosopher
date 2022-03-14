/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:41:46 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/08 15:41:48 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping", GREEN);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	ft_print(philo, "is thinking", YELLOW);
}

void	ft_eating(t_philo *philo,
		pthread_mutex_t *fork_a, pthread_mutex_t *fork_b)
{
	pthread_mutex_lock(fork_a);
	ft_print(philo, "has taken a fork", PURPLE);
	pthread_mutex_lock(fork_b);
	ft_print(philo, "has taken a fork", PURPLE);
	ft_print(philo, "is eating", BLUE);
	pthread_mutex_lock(&philo->lock);
	philo->one_must_eat--;
	philo->last_diner = ft_time();
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(fork_b);
	pthread_mutex_unlock(fork_a);
}

int	ft_philo_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if ((ft_time() - philo->last_diner) >= (long int)philo->data->time_to_die
		&& philo->data->death == 0)
	{
		ft_print(philo, "died", YELLOW);
		pthread_mutex_unlock(&philo->lock);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->lock);
	return (SUCCESS);
}

int	ft_checker(t_data *data)
{
	int	i;

	i = 0;
	ft_usleep(2);
	while (1)
	{
		i = 0;
		while (i < data->nb_of_philo)
		{
			if (ft_philo_death(&data->philo[i]) == FAILURE)
			{
				pthread_mutex_lock(&data->check_death);
				data->death = 1;
				pthread_mutex_unlock(&data->check_death);
				return (FAILURE);
			}
			i++;
			ft_usleep(2);
		}
	}
	return (SUCCESS);
}
