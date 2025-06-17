/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/17 17:35:07 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *args)
{
	int				thread_id;
	t_args			*times;
	size_t			start;

	start = ((t_thread *)args)->timer.start;
	times = ((t_thread *)args)->args;
	thread_id = ((t_thread *)args)->n;
	if ((long)timer(start) >= times->time_to_die)
	{
		printf("philosopher %d died\n", thread_id);
		return (NULL);
	}
	if ((long)timer(start) < times->time_to_eat)
	{
		printf("start: %ld\n", timer(start));
		printf("eat :%ld\n", times->time_to_eat);
		usleep(times->time_to_eat * 1000);
		printf("%ld %d is eating\n",get_current_time() - start, thread_id);
		((t_thread*)args)->timer.start = get_current_time();
	}
	printf("Current thread : %d\n\n", thread_id);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_args			*args;
	t_thread		*thread;
	int				i;

	if ((ac < 5 || ac > 6))
		return (error_exit("Error: Invalid args", ERROR_0), 1);
	if (!valid_args(av, ac))
		return (1);
	args = safe_malloc(sizeof(t_args));
	init_philo(args, av, ac);
	i = 0;
	thread = safe_malloc(sizeof(t_thread));
	thread->thread = safe_malloc(sizeof(pthread_t) * args->num_of_phil);
	thread->args = args;
	thread->timer.start = get_current_time();
	while (i < args->num_of_phil)
	{
		pthread_create(&thread->thread[i], NULL, test, (void *)thread);
		thread->n = i + 1;
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
