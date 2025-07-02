/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:46:51 by emurillo          #+#    #+#             */
/*   Updated: 2025/07/02 16:57:31 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// printf("meals had: %d\n", philo->n_meals);

void	single_routine(t_thread *philo, t_args *args)
{
	if ((int)get_long(philo, (long *)&philo->full))
		return ;
	while (!has_ended(philo))
	{
		write_status(philo, philo->n, TAKE_RIGHT_FORK);
		set_last_meal(philo);
		while (!has_ended(philo))
			mili_sleep(args->time_to_eat);
	}
}
