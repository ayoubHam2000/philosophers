/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:30:24 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 18:08:43 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static size_t	get_time_micro()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000000 + t.tv_usec);
}

void	ft_usleep(size_t time)
{
	size_t	t1;
	size_t	t2;

	t1 = get_time_micro();
	//printf("%zu, %zu, %zu, %zu\n", t1, t2, time, time - t2);
	usleep(time);
	t2 = get_time_micro() - t1;
	printf("%zu\n", t2);
	//t2 = t2 - time; 
}
