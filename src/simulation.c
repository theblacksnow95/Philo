/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/25 16:57:54 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_args *args)
{
	while (args->all_created != 1)
		;
}

void	eat_routine(t_thread *philos, t_args *args)
{
	lock_forks(philos);
	mili_sleep(args->time_to_eat);
	write_status(philos, philos->n, EAT);
	philos->n_meals++;
	if (philos->n_meals == args->meals_to_have)
		philos->full = 0;
	printf("meals had: %d\n", philos->n_meals);
	unlock_forks(philos);
}

void	*test(void *phil)
{
	t_args			*args;
	t_thread		*philos;

	wait_all_threads(((t_thread *)phil)->args);
	printf("enter test func\n");
	args = ((t_thread *)phil)->args;
	philos = (t_thread *)phil;
	if (philos->n % 2 == 0)
		usleep(philos->n * 200);
	while (!args->dinner_end)
	{
		if (!philos->full)
			return (NULL);
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
	args->timer.start = get_current_time();
	printf("%ld\n", args->timer.start);
	i = 0;
	args->all_created = 1;
	while (i < args->num_of_phil)
	{
		pthread_join(args->threads[i].id, NULL);
		i++;
	}
	return (0);
}
