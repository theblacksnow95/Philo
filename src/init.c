/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:20:29 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/21 18:39:29 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	assign_forks(t_thread *philo, t_fork *forks, int pos)
{
	int	n;

	n = philo->args->num_of_phil;
	philo->right_fork = &forks[(pos + 1) % n];
	philo->left_fork = &forks[(pos)];
	if (philo->n % 2 == 0)
	{
		philo->right_fork = &forks[pos];
		philo->left_fork = &forks[(pos + 1) % n];
	}
}

static void	init_mutex(t_args *args)
{
	int	i;

	i = 0;
	if (i < args->num_of_phil)
	{
		pthread_mutex_init(&args->mutex[i].fork, NULL);
		args->mutex->fork_id = i;
		i++;
	}
	printf("mutex done\n");
}

static int	init_threads(t_args *args)
{
	int			i;
	t_thread	*philo;

	i = 0;
	while (i < args->num_of_phil)
	{
		philo = &args->threads[i];
		philo->n = i + 1;
		philo->full = 0;
		philo->args = args;
		philo->n_meals = 0;
		philo->last_meal = 0;
		assign_forks(philo, args->mutex, i);
		i++;
	}
	printf("philos done\n");
	return (0);
}

void	data_init(t_args *args, char **av, int ac)
{
	args->num_of_phil = ft_atol(av[1]);
	args->time_to_die = ft_atol(av[2]);
	args->time_to_eat = ft_atol(av[3]);
	args->time_to_sleep = ft_atol(av[4]);
	args->threads = safe_malloc(sizeof(t_thread) * args->num_of_phil);
	args->mutex = safe_malloc(sizeof(t_fork) * args->num_of_phil);
	args->all_created = 0;
	init_mutex(args);
	init_threads(args);
	if (ac == 6)
		args->meals_to_have = ft_atol(av[5]);
	if (args->time_to_eat
		&& args->time_to_die && args->time_to_sleep)
		printf("struct init correctly\n");
}
