/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-03 11:51:52 by selango           #+#    #+#             */
/*   Updated: 2024-10-03 11:51:52 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// initialising philo.
void init_philo(t_philo *philo,t_philo *lock,pthread_mutex_t *forks)
{
    int i;
    i =0;
    while(i < philo->philo_nbr)
    {
        philo[i].philo_id = i + 1;
        philo[i].eating = 0;
        philo[i].meals_eaten =0;
        philo[i].start_time = get_current_time();
        philo[i].last_meal = get_current_time();
        philo[i].lock = &lock->lock;
        philo[i].meal_lock = &lock->meal_lock;
        philo[i].dead_lock=&lock->dead_lock;
        philo[i].dead = &lock->dead_flag;
        philo[i].l_fork = &forks[i];
        if(i == 0)
            philo[i].r_fork = &forks[philo[i].philo_nbr - 1];
        else
            philo[i].r_fork = &forks[i -1];
        i++;
    }
}

//init forks  
void init_forks(pthread_mutex_t *forks,int philo_num)
{
    int i;
    i =0;
    while(i < philo_num)
    {
        pthread_mutex_init(&forks[i],NULL);
        i++;
    }
}
void init_lock(t_philo *philo,t_lock *lock)
{
    lock->philo = philo;
    lock->dead_lock = 0;
    pthread_mutex_init(&lock->lock,NULL);
    pthread_mutex_init(&lock->meal_lock,NULL);
    pthread_mutex_init(&lock->dead_lock,NULL);
}