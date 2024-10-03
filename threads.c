/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-03 13:33:16 by selango           #+#    #+#             */
/*   Updated: 2024-10-03 13:33:16 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dead_loop initialising
int     dead_loop(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if(*philo->dead == 1)
        return(pthread_mutex_unlock(philo->dead_lock),1);
    pthread_mutex_unlock(philo->dead_lock);
    return(0);
}

