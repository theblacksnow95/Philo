/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:03:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/07/03 17:22:12 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	has_ended(t_thread *philo)
{
	int	ret;
	mutex_lock(&philo->args->smtx);
	ret = philo->args->dinner_end;
	mutex_unlock(&philo->args->smtx);
	return (ret);
}

long	get_long(t_thread *philo, long *value)
{
	long	ret;

	mutex_lock(&philo->args->smtx);
	ret = *value;
	mutex_unlock(&philo->args->smtx);
	return (ret);
}

void	set_full(t_thread *philo)
{
	mutex_lock(&philo->args->smtx);
	philo->full = 1;
	mutex_unlock(&philo->args->smtx);
}

void	incr_meals(t_thread *philo, int *value)
{
	mutex_lock(&philo->args->smtx);
	*value = *value + 1;
	mutex_unlock(&philo->args->smtx);
}

void set_timer(t_args *args)
{
	mutex_lock(&args->smtx);
	args->timer.start = timer(args->timer.start);
	mutex_unlock(&args->smtx);

}
