/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:53:11 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/25 15:49:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_args *args, int n, t_wrcds stat_code)
{
	mutex_lock(args->write);
	if (stat_code == EAT)
	{
		printf("%ld %d is eating\n", timer(args->timer.start), n);
		args->threads->last_meal = get_current_time();
	}
	if (stat_code == SLEEPING)
		printf("%ld %d sleeps\n", timer(args->timer.start), n);
	if (stat_code == DIED)
		printf("%ld %d died\n", timer(args->timer.start), n);
	if (stat_code == TAKE_RIGHT_FORK)
		printf("%ld %d has taken the right fork\n",
			timer(args->timer.start), n);
	if (stat_code == TAKE_LEFT_FORK)
		printf("%ld %d has taken the left fork\n",
			timer(args->timer.start), n);
	if (stat_code == RET_LEFT_FORK)
		printf("%ld %d has returned the left fork\n",
			timer(args->timer.start), n);
	if (stat_code == RET_RIGHT_FORK)
		printf("%ld %d has returned the right fork\n",
			timer(args->timer.start), n);
	mutex_unlock(args->write);
}
