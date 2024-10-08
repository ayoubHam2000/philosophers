/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:34:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/17 16:00:03 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_philo *philo, const char *status, int end)
{
	static size_t			old;

	pthread_mutex_lock(philo->print);
	if (!old)
		old = get_time();
	printf("%lu %zu %s\n", get_time() - old, philo->id, status);
	if (!end)
		pthread_mutex_unlock(philo->print);
}
