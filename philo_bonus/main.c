/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:52:26 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 15:52:27 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	start(t_args *args)
{
	sem_t	*sem_forks;
	sem_t	*sem_print;

	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FORKS);
	sem_forks = sem_open(SEM_FORKS, O_CREAT, 0600, args->nb_philo);
	sem_print = sem_open(SEM_PRINT, O_CREAT, 0600, 1);
	if (sem_forks == SEM_FAILED || sem_print == SEM_FAILED)
		ft_error();
	start_competition(*args);
	if (sem_close(sem_forks) != 0 || sem_close(sem_print) != 0)
		ft_error();
	if (sem_unlink(SEM_FORKS) != 0 || sem_unlink(SEM_PRINT) != 0)
		ft_error();
}

int	main(int ac, char **av)
{
	t_args		*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (0);
	if (!check_args(ac, av, args))
		help();
	if (!args->nb_philo || !args->nbr_time_to_eat)
		return (0);
	start(args);
	free(args);
	return (0);
}
