/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:41:22 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/08 15:41:24 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *philo, char *str, char *COLOR)
{
	pthread_mutex_lock(&philo->data->check_death);
	if (philo->state_dead == false && philo->data->death == 0
		&& philo->one_must_eat != 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%s%ld %d %s\n", COLOR,
			(ft_time() - philo->data->time_starter), philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_unlock(&philo->data->check_death);
}
