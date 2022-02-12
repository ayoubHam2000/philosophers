/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:54:41 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 09:54:52 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	help(void)
{
	put_str("\nError\n./philo <number_of_philosophers>");
	put_str(" <time_to_die> <time_to_eat> ");
	put_str("<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n\n");
	exit(0);
}
