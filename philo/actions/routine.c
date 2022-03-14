/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:41:56 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/08 15:41:57 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_routine(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->check_death);
		if (philo->data->death == 0)
		{
			pthread_mutex_unlock(&philo->data->check_death);
			if (philo->id % 2 == 0)
				ft_eating(philo, philo->left_fork, philo->right_fork);
			else
				ft_eating(philo, philo->right_fork, philo->left_fork);
			ft_sleeping(philo);
			ft_thinking(philo);
			ft_usleep(1);
			if (philo->one_must_eat == 0)
				return (FAILURE);
		}
		else
		{
			pthread_mutex_unlock(&philo->data->check_death);
			return (FAILURE);
		}
	}
}

int	*routine(t_philo *philo)
{
	if (philo->data->nb_of_philo > 1)
		ft_routine(philo);
	else
	{
		ft_print(philo, "has taken a fork", PURPLE);
		ft_usleep(philo->data->time_to_die);
	}
	return (SUCCESS);
}
