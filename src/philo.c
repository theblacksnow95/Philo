/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/10 16:18:45 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *args)
{
	pthread_t		thread_id;
	t_args			*times;
	size_t			stop;

	stop = get_current_time();
	times = (t_args *)args;
	thread_id = pthread_self();
	usleep(10000);
	if ((get_current_time() - stop) >= (size_t)times->time_to_die)
	{
		printf("philosopher %ld died\n", thread_id);
		return (NULL);
	}
	if ((get_current_time() - stop) < (size_t)times->time_to_eat)
	{
		printf("stop: %ld\n", (get_current_time() - stop));
		printf("eat :%d\n", times->time_to_eat);
		printf("Philosopher %ld is eating\n", thread_id);
	}
	printf("Current thread ID: %lu\n\n", (unsigned long)thread_id);
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
	init_philo(args, av, ac);
	i = 0;
	thread = malloc(sizeof(t_thread));
	thread->thread = malloc(sizeof(pthread_t) * args->num_of_phil);
	while (i < args->num_of_phil)
	{
		pthread_create(&thread->thread[i], NULL, test, (void *)args);
		usleep(30000);
		i++;
	}
	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_join(thread->thread[i], NULL);
		i++;
	}
	print_struct(args, ac);
	free_all(thread, args);
	return (0);
}
