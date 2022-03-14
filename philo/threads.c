/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:18:35 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/02 16:18:37 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_phtread_join(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->checker, NULL) != SUCCESS)
		return (FAILURE);
	while (i < data->nb_of_philo)
	{
		if (pthread_join(data->philo[i].philo_th, NULL) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_create(&data->philo[i].philo_th, NULL,
				(void *)routine, (void *)&data->philo[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	if (pthread_create(&data->checker, NULL,
			(void *)ft_checker, (void *)data) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
