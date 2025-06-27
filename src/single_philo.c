/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:46:51 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 14:37:29 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// printf("meals had: %d\n", philo->n_meals);

void	single_routine(t_thread *philo, t_args *args)
{
	if (philo->full)
		return ;
	while (!args->dinner_end)
	{
		write_status(philo, philo->n, TAKE_RIGHT_FORK);
		philo->last_meal = get_current_time();
		while (!args->dinner_end)
			mili_sleep(args->time_to_eat);
	}
}
