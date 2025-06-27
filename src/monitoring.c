/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:47:17 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 18:24:37 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	for debug the time to die inside check_philo_died;
			printf("last meal: %ld\n", philo->last_meal);
		printf("died at: %ld\n", get_current_time());
		printf("time passed: %ld\n", stop);
*/

void	set_dinner_end(t_args *args)
{
	mutex_lock(args->smtx);
	args->dinner_end = 1;
	mutex_unlock(args->smtx);
}

t_wrcds	all_running(t_args *args)
{
	mutex_lock(args->smtx);
	if (args->count_running == (int)args->num_of_phil)
	{
		args->all_running = 1;
		return (TRUE);
	}
	mutex_unlock(args->smtx);
	return (FALSE);
}

int	check_philo_died(t_thread *philo)
{
	long	stop;
	long	die_spam;

	if (philo->full)
		return (0);
	stop = get_current_time() - (size_t)philo->last_meal;
	die_spam = philo->args->time_to_die;
	if (stop > die_spam)
	{
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *data)
{
	int		i;
	t_args	*args;

	args = (t_args *)data;
	while (all_running(args) == FALSE)
		usleep(70);
	while (!args->dinner_end)
	{
		if (args->threads->full)
			break ;
		i = 0;
		while (i < args->num_of_phil && !args->dinner_end)
		{
			if (check_philo_died(&args->threads[i]))
			{
				write_status(&args->threads[i], args->threads[i].n, DIED);
				set_dinner_end(args);
			}
			i++;
			usleep(200);
		}
	}
	return (NULL);
}

void	monitoring(t_args *args)
{
	if (pthread_create(&args->monitor, NULL, monitor_routine, (void *)args)
		== -1)
		error_exit("thread creation", E_THREAD);
}
