/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:42:39 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 15:54:54 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	*supervisor_thread(void *p)
{
	t_philo	*philo;

	philo = p;
	while (1)
	{
		if ((get_time() - philo->t_last_meal) > philo->args.time_to_die \
			&& !philo->is_eating)
		{
			print_status(philo, DIED, 1);
			exit(EXIT_DEAD);
		}
		usleep(200);
	}
}

static void	start_supervisor(t_philo *philo)
{
	pthread_t	supervisor;

	if (pthread_create(&supervisor, NULL, supervisor_thread, philo) != 0)
		exit(EXIT_FAILD);
	pthread_detach(supervisor);
}

static t_philo	*init_philo(int id, t_args *args)
{
	t_philo	*philo;
	sem_t	*sem_forks;
	sem_t	*sem_print;

	sem_forks = sem_open(SEM_FORKS, 0);
	sem_print = sem_open(SEM_PRINT, 0);
	if (sem_forks == SEM_FAILED || sem_print == SEM_FAILED)
		exit(EXIT_FAILD);
	philo = malloc(sizeof(philo));
	if (!philo)
		exit(EXIT_FAILD);
	philo->id = id + 1;
	philo->is_eating = 0;
	philo->nbr_eat = 0;
	philo->t_last_meal = get_time();
	philo->args = *args;
	philo->sem_forks = sem_forks;
	philo->sem_print = sem_print;
	return (philo);
}

void	kla_bzaf(t_philo *philo)
{
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
	exit(EXIT_MIN_EATING);
}

void	philo_process(int id, t_args args)
{
	t_philo	*philo;

	philo = init_philo(id, &args);
	start_supervisor(philo);
	while (1)
	{
		sem_wait(philo->sem_forks);
		print_status(philo, TAKEN_A_FORK, 0);
		sem_wait(philo->sem_forks);
		print_status(philo, TAKEN_A_FORK, 0);
		print_status(philo, EATING, 0);
		philo->is_eating = 1;
		philo->t_last_meal = get_time();
		usleep(philo->args.time_to_eat * 1000 - 1000);
		philo->is_eating = 0;
		philo->nbr_eat++;
		if (philo->nbr_eat == philo->args.nbr_time_to_eat)
			kla_bzaf(philo);
		print_status(philo, SLEEPING, 0);
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		usleep(philo->args.time_to_sleep * 1000 - 1000);
		print_status(philo, THINKING, 0);
	}
}
