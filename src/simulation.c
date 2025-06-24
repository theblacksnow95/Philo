/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/24 11:33:58 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_args *args)
{
	while (args->all_created != 1)
		;
}

void	*test(void *phil)
{
	int				thread_id;
	t_args			*args;
	t_thread		*philos;
	size_t			start;

	args = ((t_thread *)phil)->args;
	wait_all_threads(args);
	start = args->timer.start;
	philos = (t_thread *)phil;
	thread_id = ((t_thread *)phil)->n;
	if (get_current_time() - start >= (size_t)args->time_to_die)
	{
		printf("philosopher %d died\n", thread_id);
		printf("timer now :  %ld\n", get_current_time());
		printf("time start:%ld\n", start);
		printf("time diff :%ld\n", get_current_time() - start);
		printf("died :%ld\n", args->time_to_die);
		return (NULL);
	}
	else if (get_current_time() - start < (size_t)args->time_to_eat)
	{
		lock_forks(philos);
		printf("start: %ld\n", get_current_time() - start);
		printf("eat :%ld\n", args->time_to_eat);
		mili_sleep(args->time_to_eat);
		printf("%ld %d is eating\n", timer(start), thread_id);
		unlock_forks(philos);
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
	args->timer.start = get_current_time();
	while (i < args->num_of_phil)
	{
		pthread_create(&args->threads[i].id, NULL, test, (void *)args->threads);
		i++;
	}
	i = 0;
	args->all_created = 1;
	printf("%ld\n", args->timer.start);
	while (i < args->num_of_phil)
	{
		pthread_join(args->threads[i].id, NULL);
		i++;
	}
	return (0);
}
