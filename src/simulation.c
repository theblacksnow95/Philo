/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/26 18:06:20 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	printf("value running %d\n", *value);
	mutex_unlock(args->smtx);
}

void	wait_all_threads(t_args *args)
{
	while (check_all_created(args) == FALSE)
		usleep(10);
}

void	eat_routine(t_thread *philos, t_args *args)
{
	lock_forks(philos);
	philos->last_meal = get_current_time();
	mili_sleep(args->time_to_eat);
	write_status(philos, philos->n, EAT);
	philos->n_meals++;
	if (philos->args->meals_to_have > 0 &&
		philos->n_meals == args->meals_to_have)
		philos->full = 1;
	printf("meals had: %d\n", philos->n_meals);
	unlock_forks(philos);
}

void	*test(void *data)
{
	t_args			*args;
	t_thread		*philos;

	wait_all_threads(((t_thread *)data)->args);
	args = ((t_thread *)data)->args;
	philos = (t_thread *)data;
	printf("enter test func\n");
	philos->last_meal = get_current_time();
	set_running(args, &args->all_running);
	usleep(20);
	if (philos->n % 2 == 0)
		usleep(philos->n * 200);
	while (!args->dinner_end)
	{
		if (philos->full)
			break ;
		eat_routine(philos, args);
		write_status(philos, philos->n, SLEEPING);
		mili_sleep(args->time_to_sleep);
	}
	return (NULL);
}

int	start_simulation(t_args *args)
{
	int	i;

	i = 0;
	if (args->meals_to_have == 0)
		return (0);
	printf("Start sim\n");
	while (i < args->num_of_phil)
	{
		pthread_create(&args->threads[i].id, \
			NULL, test, &args->threads[i]);
		i++;
	}
	monitoring(args);
	args->timer.start = get_current_time();
	printf("%ld\n", args->timer.start);
	set_all_created(args);
	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_join(args->threads[i].id, NULL);
		i++;
	}
	return (0);
}
