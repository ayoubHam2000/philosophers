/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:54:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 16:27:17 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_args(int ac, char **av, t_args *args)
{
	if (ac == 5 || ac == 6)
	{
		args->nb_philo = ft_atoi(av[1]);
		args->time_to_die = ft_atoi(av[2]);
		args->time_to_eat = ft_atoi(av[3]);
		args->time_to_sleep = ft_atoi(av[4]);
		if ((int)(args->nb_philo) < 0 || (int)(args->time_to_die) < 0 \
			|| (int)(args->time_to_eat) < 0 || (int)(args->time_to_sleep) < 0)
			return (0);
		if (ac == 6)
			args->nbr_time_to_eat = ft_atoi(av[5]);
		else
			args->nbr_time_to_eat = (size_t)(-1);
		if ((int)(args->nbr_time_to_eat) < 0 && args->nbr_time_to_eat != (size_t)(-1))
			return (0);
		return (1);
	}
	return (0);
}
