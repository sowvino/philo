/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 12:07:38 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 12:07:38 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo
{
	pthread_t		thread;
	int				philo_id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			end_time;
	int				philo_nbr;
	int				nbr_meals_fed;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
}					t_philo;

typedef struct lock
{
	int				dead_flag;
	pthread_mutex_t	lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philo;
}					t_lock;

int					ft_isdigit(char c);
void				parse_input(t_philo *philo, char **argv);
void				error_msg(char *error);
void				get_current_time(void);
void				init_philo(t_philo *philo, t_philo *lock,
						pthread_mutex_t *forks);
void 				init_forks(pthread_mutex_t *forks,int philo_num);
void 				init_lock(t_philo *philo,t_lock *lock);

#endif