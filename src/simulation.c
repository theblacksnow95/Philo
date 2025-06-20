/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/20 18:28:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_args *args)
{
	while (!args->all_created)
		;
}

void	*test(void *args)
{
	int				thread_id;
	t_args			*times;
	size_t			start;

	start = ((t_thread *)args)->timer.start;
	times = ((t_args *)args);
	thread_id = ((t_args *)args)->threads->n;
	wait_all_threads((t_args *)args);
	usleep(10000);
	if (timer(start) >= (size_t)times->time_to_die)
	{
		printf("philosopher %d died\n", thread_id);
		printf("start: %ld\n", get_current_time() - start);
		printf("eat :%ld\n", times->time_to_eat);
		return (NULL);
	}
	if (timer(start) < (size_t)times->time_to_eat)
	{
		printf("start: %ld\n", get_current_time() - start);
		printf("eat :%ld\n", times->time_to_eat);
		usleep(times->time_to_eat * 1000);
		printf("%ld %d is eating\n", get_current_time() - start, thread_id);
		((t_thread *)args)->timer.start = get_current_time();
	}
	printf("Current thread : %d\n\n", thread_id);
	return (NULL);
}

int	start_simulation(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_create(&args->threads->id[i], NULL, test, (void *)args);
		args->threads->n = i + 1;
		i++;
	}
	i = 0;
	args->all_created = 1;
	while (i < args->num_of_phil)
	{
		pthread_join(args->threads->id[i], NULL);
		i++;
	}
	return (0);
}
