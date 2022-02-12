/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   competition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:18:34 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 18:35:50 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_thread(void *p)
{
	t_philo	*philo;

	philo = p;
	while (1)
	{
		pthread_mutex_lock(philo->m_fork1);
		print_status(philo, TAKEN_A_FORK);
		pthread_mutex_lock(philo->m_fork2);
		print_status(philo, EATING);
		philo->is_eating = 1;
		philo->t_last_meal = get_time();
		usleep(philo->args->time_to_eat * 1000);
		philo->is_eating = 0;
		philo->nbr_eat++;
		print_status(philo, SLEEPING);
		pthread_mutex_unlock(philo->m_fork1);
		pthread_mutex_unlock(philo->m_fork2);
		usleep(philo->args->time_to_sleep * 1000);
		print_status(philo, THINKING);	
	}
}

int	start_competition(t_philo *philos)
{
	pthread_t	*threads;
	size_t		i;
	int			res;

	threads = malloc(sizeof(pthread_t) * (philos->args->nb_philo));
	if (!threads)
		return (0);
	res = 1;
	i = 0;
	while (i < philos->args->nb_philo)
	{
		if (pthread_create(threads + i, NULL, philo_thread, philos + i) != 0)
			break ;
		pthread_detach(threads[i]);
		i = i + 2;
		if (i > philos->args->nb_philo && i % 2 == 0)
		{
			i = 1;
			usleep(50);
		}
	}
	if (i < philos->args->nb_philo)
		res = 0;
	free(threads);
	return (res);
}
