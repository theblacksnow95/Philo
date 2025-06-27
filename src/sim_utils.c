/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:33:22 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 18:22:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal(t_thread *philo)
{
	mutex_lock(philo->args->smtx);
	philo->last_meal = get_current_time();
	mutex_unlock(philo->args->smtx);
}

t_wrcds	check_all_created(t_args *args)
{
	mutex_lock(args->smtx);
	if (args->all_created == 1)
		return (TRUE);
	mutex_unlock(args->smtx);
	return (FALSE);
}

void	set_all_created(t_args *args)
{
	mutex_lock(args->smtx);
	args->all_created = 1;
	mutex_unlock(args->smtx);
}

void	set_running(t_args *args, int *value)
{
	mutex_lock(args->smtx);
	*value = *value + 1;
	mutex_unlock(args->smtx);
}

void	wait_all_threads(t_args *args)
{
	while (check_all_created(args) == FALSE)
		usleep(10);
}
