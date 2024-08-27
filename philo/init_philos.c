/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:56:09 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 15:57:28 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static size_t	left_fork(size_t i, size_t nbp)
{
	if (!i)
		return (nbp - 1);
	return (i - 1);
}

t_philo	*init_philos(t_args *args)
{
	size_t			i;
	t_philo			*philos;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t *arr_critical_section;
	pthread_mutex_t *mtx_print;

	philos = malloc(args->nb_philo * sizeof(t_philo));
	m_forks = malloc(sizeof(pthread_mutex_t) * (args->nb_philo));
	arr_critical_section = malloc(sizeof(pthread_mutex_t) * (args->nb_philo));
	mtx_print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mtx_print, NULL);
	if (!philos || !m_forks)
		return (NULL);
	i = -1;
	while (++i < args->nb_philo)
	{
		pthread_mutex_init(m_forks + i, NULL);
		pthread_mutex_init(arr_critical_section + i, NULL);
		philos[i].id = i + 1;
		philos[i].args = args;
		philos[i].is_eating = 0;
		philos[i].nbr_eat = 0;
		philos[i].flag = 0;
		philos[i].t_last_meal = 0;
		philos[i].m_fork1 = m_forks + left_fork(i, args->nb_philo);
		philos[i].m_fork2 = m_forks + i;
		philos[i].critical_section = arr_critical_section + i;
		philos[i].print = mtx_print;
	}
	return (philos);
}
