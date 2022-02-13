/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:34:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 14:36:24 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	print_status(t_philo *philo, const char *status, int stop)
{
	static size_t	old;

	if (!old)
		old = philo->t_last_meal;
	sem_wait(philo->sem_print);
	printf("%lu %zu %s\n", get_time() - old, philo->id, status);
	if (!stop)
		sem_post(philo->sem_print);
}
