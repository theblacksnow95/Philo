/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:31:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/21 18:58:54 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_args *args)
{
	while (args->all_created != 1)
		;
	printf("All threads synched\n");
}

void	*test(void *phil)
{
	int				thread_id;
	t_args			*args;
	t_thread		*philos;
	size_t			start;

	start = ((t_thread *)phil)->args->timer.start;
	args = ((t_thread *)phil)->args;
	philos = (t_thread *)phil;
	thread_id = ((t_thread *)phil)->n;
	wait_all_threads(args);
	if (get_current_time() - start >= (size_t)args->time_to_die)
	{
		printf("philosopher %d died\n", thread_id);
		printf("timer diff %ld\n", timer(start));
		printf("died :%ld\n", args->time_to_die);
		return (NULL);
	}
	else if (get_current_time() - start < (size_t)args->time_to_eat)
	{
		pthread_mutex_lock(&philos->left_fork->fork);
		pthread_mutex_lock(&philos->right_fork->fork);
		printf("start: %ld\n", get_current_time() - start);
		printf("eat :%ld\n", args->time_to_eat);
		usleep(args->time_to_eat * 1000);
		printf("%ld %d is eating\n", timer(start), thread_id);
		pthread_mutex_unlock(&philos->left_fork->fork);
		pthread_mutex_unlock(&philos->right_fork->fork);
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
		i++;
	}
	i = 0;
	args->timer.start = get_current_time();
	args->all_created = 1;
	while (i < args->num_of_phil)
	{
		pthread_join(args->threads[i].id, NULL);
		i++;
	}
	return (0);
}
