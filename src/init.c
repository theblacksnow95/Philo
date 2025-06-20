/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:20:29 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/20 18:11:16 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	init_threads(t_args *args)
{

	args->threads = safe_malloc(sizeof(t_thread));
	args->threads->id = safe_malloc(sizeof(pthread_t) * args->num_of_phil);
	args->threads->args = args;
	args->threads->timer.start = get_current_time();
	args->all_created = 0;
	args->threads->args = args;
	return (0);
}

void	init_philo(t_args *args, char **av, int ac)
{
	args->num_of_phil = ft_atol(av[1]);
	args->time_to_die = ft_atol(av[2]);
	args->time_to_eat = ft_atol(av[3]);
	args->time_to_sleep = ft_atol(av[4]);
	init_threads(args);
	if (ac == 6)
		args->meals_to_have = ft_atol(av[5]);
	if (args->time_to_eat
		&& args->time_to_die && args->time_to_sleep)
		printf("struct init correctly\n");
}
