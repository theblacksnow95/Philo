/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/07/02 16:52:47 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_routine(t_thread *philo, t_args *args)
{
	long	think_time;

	write_status(philo, philo->n, THINK);
	if (args->num_of_phil % 2 == 0)
	{
		mili_sleep(1);
		return ;
	}
	else
	{
		if (philo->last_meal == 0)
			return ;
		think_time = (args->time_to_eat * 2 - args->time_to_sleep);
		if (think_time <= 0)
			think_time = 0;
		mili_sleep(think_time * 0.42);
	}
}

	// printf("meals had: %d\n", philos->n_meals);

void	eat_routine(t_thread *philo, t_args *args)
{
	lock_forks(philo);
	set_last_meal(philo);
	write_status(philo, philo->n, EAT);
	mili_sleep(args->time_to_eat);
	incr_meals(philo, &philo->n_meals);
	if (philo->args->meals_to_have > 0 && \
		philo->n_meals == args->meals_to_have)
		set_full(philo);
	unlock_forks(philo);
}

void	*simulation_routine(void *data)
{
	t_args			*args;
	t_thread		*philo;

	wait_all_threads(((t_thread *)data)->args);
	args = ((t_thread *)data)->args;
	philo = (t_thread *)data;
	philo->last_meal = get_current_time();
	set_running(args, &args->count_running);
	usleep(20);
	if (args->num_of_phil == 1)
		single_routine(philo, args);
	if (philo->n % 2 == 0)
		usleep(philo->n * 200);
	while (!has_ended(philo))
	{
		if (philo->full)
			break ;
		eat_routine(philo, args);
		write_status(philo, philo->n, SLEEPING);
		mili_sleep(args->time_to_sleep);
		think_routine(philo, args);
	}
	return (NULL);
}

int	start_simulation(t_args *args)
{
	int	i;

	i = 0;
	if (args->meals_to_have == 0)
		return (0);
	while (i < args->num_of_phil)
	{
		pthread_create(&args->threads[i].id, \
			NULL, simulation_routine, &args->threads[i]);
		i++;
	}
	monitoring(args);
	args->timer.start = get_current_time();
	set_all_created(args);
	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_join(args->threads[i].id, NULL);
		i++;
	}
	pthread_join(args->monitor, NULL);
	return (0);
}
