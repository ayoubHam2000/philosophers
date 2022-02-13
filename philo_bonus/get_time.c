/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:28:14 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 15:54:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
