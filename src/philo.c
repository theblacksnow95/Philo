/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/06 13:56:34 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *args)
{
	pthread_t	thread_id;

	(void)args;
	thread_id = pthread_self();
	printf("Current thread ID: %lu\n", (unsigned long)thread_id);
	usleep(20000);
	pthread_exit(NULL);
	return (NULL);
}


int	main(int ac, char **av)
{
	t_args		*args;
	t_thread	*thread;
	int			i;

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
		pthread_create(&thread->thread[i], NULL, test, NULL);
		usleep(30000);
		i++;
	}
	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_join(thread->thread[i], NULL);
		i++;
	}
	free(args);
	free_all(thread);
	return (0);
}
