/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:34:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 19:53:44 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_philo *philo, const char *status)
{
	static size_t			old;
	static pthread_mutex_t	print;

	if (!old)
	{
		old = get_time();
		pthread_mutex_init(&print, NULL);
	}
	pthread_mutex_lock(&print);
	printf("%lu %zu %s\n", get_time() - old, philo->id, status);
	pthread_mutex_unlock(&print);
}
