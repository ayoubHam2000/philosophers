/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:20:04 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 12:46:36 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*task(void *p)
{
	int	i;

	i = *((int *)p);
	printf("start Task N = %d\n", i);
	sleep(i);
	printf("End Task N = %d\n", i);
	return (NULL);
}

int	main()
{
	int			thread_count;
	pthread_t	*threads;
	int			i;
	int			*p;

	thread_count = 3;
	threads = malloc(sizeof(pthread_t) * thread_count);
	p = malloc(sizeof(int) * thread_count);
	i = 0;
	while (i < thread_count)
	{
		p[i] = (i + 5);
		pthread_create(threads + i, NULL, task, p + (thread_count - i - 1));
		pthread_detach(threads[i]);
		usleep(100);
		i++;
	}
	free(threads);
	/*i = 0;
	while (i < thread_count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}*/
	threads = NULL;
	system("leaks a.out");
	sleep(9);
	printf("End Parent\n");
}
