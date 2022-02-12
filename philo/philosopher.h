/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:53:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/12 20:12:21 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TAKEN_A_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_args
{
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			nbr_time_to_eat;
	size_t			nb_philo;
}	t_args;

typedef struct philo
{
	size_t			id;
	size_t			nbr_eat;
	size_t			t_last_meal;
	t_args			*args;
	int				is_eating;
	int				flag;
	pthread_mutex_t	*m_fork1;
	pthread_mutex_t	*m_fork2;
}	t_philo;

//code
t_philo		*init_philos(t_args *args);
int			start_competition(t_philo *philos);
pthread_t	*start_supervisor(t_philo *philos);
void		*philo_thread(void *p);
void		*supervisor_thread(void *p);
void		print_status(t_philo *philo, const char *status);

//utils
int			ft_atoi(const char *str);
void		put_str(const char *str);
void		help(void);
int			check_args(int ac, char **av, t_args *args);
size_t		get_time();

#endif
