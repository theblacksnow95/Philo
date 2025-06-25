/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/25 12:12:54 by emurillo         ###   ########.fr       */
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
		write_status(args, EAT);
		unlock_forks(philos);
}


void	*test(void *phil)
{
	int				thread_id;
	t_args			*args;
	t_thread		*philos;

	printf("enter test func\n");
	args = ((t_thread *)phil)->args;
	wait_all_threads(args);
	philos = (t_thread *)phil;
	thread_id = ((t_thread *)phil)->n;
	while (!args->dinner_end)
	{
		eat_routine(philos, args);
		write_status(args, SLEEPING);
		mili_sleep(args->time_to_sleep);
	}
	printf("Current thread : %d\n\n", thread_id);
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
		pthread_create(&args->threads[i].id, NULL, test, (void *)args->threads);
		printf("thread (%d) created\n", i + 1);
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
