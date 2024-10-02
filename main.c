/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 12:52:29 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 12:52:29 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


/*
input [nbr of philo,time_to_die,time_to_eat,time_to_sleep]
./philo [5,800,200,200,optional]
*/

int main(int argc,char **argv)
{
    t_table table;
    if(argc != 5 || argc != 6)
    {
        error_msg("Enter correct number of arguments\n");
        return(1);
    }
    else
    {
        parse_input(&table,argv);
        data_init(&table);
        dinner_start(&table);
        clean(&table);
    }
}