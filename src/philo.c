/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/07 12:39:42 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofdat() errror\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*test(void *args)
{
	pthread_t		thread_id;
	t_args			times;
	size_t			stop;

	stop = get_current_time();
	times = *(t_args *)args;
	thread_id = pthread_self();
	if ((get_current_time() - stop) < times.time_to_eat)
	{
		printf("stop: %ld\n", stop);
		printf("eat :%ld\n", times.time_to_eat);
		printf("Philosopher %ld is eating\n", thread_id);
	}
	if ((get_current_time() - stop) == times.time_to_die)
	{
		printf("philosopher %ld died\n", thread_id);
		return (NULL);
	}
	printf("Current thread ID: %lu\n", (unsigned long)thread_id);
	usleep(20000);
	pthread_exit(NULL);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_args			*args;
	t_thread		*thread;
	int				i;

	if ((ac < 5 || ac > 6) || !valid_args(av, ac))
		return (printf("Error: non valid args\n"), 1);
	args = malloc(sizeof(t_args));
	if (!args)
		return (printf("Error: malloc allocation\n"), 1);
	init_philo(args, av, ac);
	i = 0;
	thread = malloc(sizeof(t_thread));
	thread->thread = malloc(sizeof(pthread_t) * args->num_of_phil);
	while (i < args->num_of_phil)
	{
		pthread_create(&thread->thread[i], NULL, test, (void *)&args);
		usleep(30000);
		i++;
	}
	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_join(thread->thread[i], NULL);
		i++;
	}
	free_all(thread, args);
	return (0);
}
