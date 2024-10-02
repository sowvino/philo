/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 13:23:37 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 13:23:37 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*convert arg to int numbers checklist:
1.actual nbr
2.not > INT_MAX
3.timestamps > 60ms
*/

void    parse_input(t_table *table,char **argv)
{
    table->philo_nbr = ft_atol(argv[1]);
}