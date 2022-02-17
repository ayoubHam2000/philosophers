/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_competition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:52:02 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/17 16:06:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	kill_children(int *pids, int len, int status)
{
	len--;
	while (len >= 0)
	{
		kill(pids[len], SIGKILL);
		len--;
	}
	if (status == EXIT_FAILD)
		ft_error();
	exit(0);
}

static void	waiting(int *pids, int nbr_children)
{
	int	pid;
	int	status;
	int	exit_status;
	int	nb_min_eat;

	pid = waitpid(0, &status, WUNTRACED | WCONTINUED);
	nb_min_eat = 0;
	while (pid != -1)
	{
		exit_status = ((status >> 8) & 0xff);
		if (exit_status == EXIT_FAILD)
			kill_children(pids, nbr_children, EXIT_FAILD);
		else if (exit_status == EXIT_DEAD)
			kill_children(pids, nbr_children, EXIT_DEAD);
		pid = waitpid(0, &status, WUNTRACED | WCONTINUED);
	}
}

void	start_competition(t_args args)
{
	int		*pids;
	size_t	i;

	pids = malloc(sizeof(int) * (args.nb_philo));
	if (!pids)
		ft_error();
	i = -1;
	while (++i < args.nb_philo)
	{
		pids[i] = fork();
		if (pids[i] == -1)
		{
			kill_children(pids, i, EXIT_FAILD);
			ft_error();
		}
		if (!pids[i])
		{
			philo_process(i, args);
			exit(0);
		}
	}
	waiting(pids, args.nb_philo);
	free(pids);
}
