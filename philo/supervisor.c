/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:32:05 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/17 16:00:36 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	is_min_eating_done(t_philo *philo, size_t *min_eating)
{
	if (!(philo->flag) && philo->nbr_eat == philo->args->nbr_time_to_eat)
	{
		philo->flag = 1;
		(*min_eating)++;
	}
	if (*min_eating == philo->args->nb_philo)
		return (1);
	return (0);
}

void	*supervisor_thread(void *p)
{
	t_philo	*philos;
	size_t	min_eating;
	int		pause_time;
	size_t	id;

	philos = p;
	id = 0;
	pause_time = (50);
	while (1)
	{
		if ((get_time() - philos[id].t_last_meal) > philos->args->time_to_die \
			&& !philos[id].is_eating)
		{
			print_status(philos + id, DIED, 1);
			return (NULL);
		}
		if (philos->args->nbr_time_to_eat != (size_t)(-1) && \
			is_min_eating_done(philos + id, &min_eating))
		{
			return (NULL);
		}
		id = (id + 1) % (philos->args->nb_philo);
		usleep(pause_time);
	}
}

pthread_t	*start_supervisor(t_philo *philos)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t));
	if (!thread)
		return (NULL);
	if (pthread_create(thread, NULL, supervisor_thread, philos) != 0)
	{
		free(thread);
		return (NULL);
	}
	return (thread);
}
