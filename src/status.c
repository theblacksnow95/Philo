/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:53:11 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/25 16:55:32 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_thread *philo, int n, t_wrcds stat_code)
{
	mutex_lock(philo->args->write);
	if (stat_code == EAT)
	{
		printf("%ld %d is eating\n", timer(philo->args->timer.start), n);
		philo->last_meal = get_current_time();
	}
	if (stat_code == SLEEPING)
		printf("%ld %d is sleeping\n", timer(philo->args->timer.start), n);
	if (stat_code == DIED)
		printf("%ld %d died\n", timer(philo->args->timer.start), n);
	if (stat_code == TAKE_RIGHT_FORK)
		printf("%ld %d has taken a fork\n",
			timer(philo->args->timer.start), n);
	if (stat_code == TAKE_LEFT_FORK)
		printf("%ld %d has taken a fork\n",
			timer(philo->args->timer.start), n);
	if (stat_code == RET_LEFT_FORK)
		printf("%ld %d has returned a fork\n",
			timer(philo->args->timer.start), n);
	if (stat_code == RET_RIGHT_FORK)
		printf("%ld %d has returned a fork\n",
			timer(philo->args->timer.start), n);
	mutex_unlock(philo->args->write);
}
