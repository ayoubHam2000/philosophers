/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:54:41 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 15:56:08 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	help(void)
{
	printf("\nError\n./philo <number_of_philosophers>");
	printf(" <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n\n");
	exit(0);
}
