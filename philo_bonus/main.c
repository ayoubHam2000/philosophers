/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:52:26 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 17:27:35 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_args		*args;
	t_philo		*philos;
	pthread_t	*supervisor;

	args = malloc(sizeof(t_args));
	if (!args)
		return (0);
	if (!check_args(ac, av, args))
		help();
	if (!args->nb_philo || !args->nbr_time_to_eat)
		return (0);
	philos = init_philos(args);
	if (!philos)
		return (0);
	if (!start_competition(philos))
		return (0);
	supervisor = start_supervisor(philos);
	if (!supervisor)
		return (0);
	pthread_join(*supervisor, NULL);
	return (0);
}
