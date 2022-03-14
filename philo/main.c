/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:44:10 by ccalas            #+#    #+#             */
/*   Updated: 2022/03/08 15:44:11 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of args\n");
		return (FAILURE);
	}
	else
	{
		while (i < ac)
		{
			if (ft_str_isdigit(av[i]) == false || ft_atoi(av[i]) <= 0
				|| ft_atoi(av[i]) > 2147483647)
			{
				printf("Invalid args\n");
				return (FAILURE);
			}
			i++;
		}
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_check_args(ac, av) == FAILURE)
		return (EXIT_FAILURE);
	ft_init_data(&data, ac, av);
	ft_init_philo(&data);
	if (ft_create_thread(&data) == FAILURE)
	{
		ft_free(&data);
		return (EXIT_FAILURE);
	}
	if (ft_phtread_join(&data) == FAILURE)
	{
		ft_free(&data);
		return (EXIT_FAILURE);
	}
	ft_free(&data);
	return (EXIT_SUCCESS);
}
