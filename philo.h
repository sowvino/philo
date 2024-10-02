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
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef pthread_mutex_t	mtx;
typedef  struct s_table t_table;

typedef struct s_fork
{
	mtx					fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	pthread_t			thread;
	int					philo_id;
	long				meals_counter;
	bool				full;
	mtx					*right_fork;
	mtx					*left_fork;
    t_table             *table;
}                   t_philo;

typedef  struct s_table
{
    size_t				meals_eaten;
    int                 philo_nbr;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;
    bool                end_time;
    t_fork              *fork;
    t_philo             *philo;
}               t_table;

void error_msg(char *error);

#endif
