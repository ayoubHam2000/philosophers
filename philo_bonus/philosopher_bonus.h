/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:43:47 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 15:55:47 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

# define TAKEN_A_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

# define SEM_FORKS "SEM_FORKS"
# define SEM_PRINT "SEM_PRINT"

# define EXIT_DEAD 0
# define EXIT_FAILD 1
# define EXIT_MIN_EATING 2

typedef struct s_args
{
	size_t	time_to_eat;
	size_t	time_to_die;
	size_t	time_to_sleep;
	size_t	nbr_time_to_eat;
	size_t	nb_philo;
}	t_args;

typedef struct philo
{
	size_t	id;
	size_t	nbr_eat;
	size_t	t_last_meal;
	t_args	args;
	sem_t	*sem_forks;
	sem_t	*sem_print;
	sem_t *sem_critical_sec;
}	t_philo;

//code
void	start_competition(t_args args);
void	philo_process(int id, t_args args);
void	print_status(t_philo *philo, const char *status, int stop);

//utils
int		ft_atoi(const char *str);
void	help(void);
int		check_args(int ac, char **av, t_args *args);
size_t	get_time(void);
void	ft_error(void);

#endif
