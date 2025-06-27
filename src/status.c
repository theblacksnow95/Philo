/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:53:11 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 10:42:59 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_thread *philo, int n, t_wrcds stat_code)
{
	if (philo->full)
		return ;
	mutex_lock(philo->args->write);
	if (stat_code == EAT && !philo->args->dinner_end)
		printf("%ld %d is eating\n", timer(philo->args->timer.start), n);
	if (stat_code == SLEEPING && !philo->args->dinner_end)
		printf("%ld %d is sleeping\n", timer(philo->args->timer.start), n);
	if (stat_code == DIED && !philo->args->dinner_end)
		printf("%ld %d died\n", timer(philo->args->timer.start), n);
	if (stat_code == THINK && !philo->args->dinner_end)
		printf("%ld %d is thinking\n", timer(philo->args->timer.start), n);
	if ((stat_code == TAKE_RIGHT_FORK || stat_code == TAKE_LEFT_FORK)
		&& !philo->args->dinner_end)
		printf("%ld %d has taken a fork\n",
			timer(philo->args->timer.start), n);
	mutex_unlock(philo->args->write);
}
