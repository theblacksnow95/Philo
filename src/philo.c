/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/31 19:21:42 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_args *args, char **av, int ac)
{
	args->num_of_phil = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->meals_to_have = ft_atoi(av[5]);
	if (args->time_to_eat
		&& args->time_to_die && args->time_to_sleep)
		printf("struct init correctly\n");
}


void	print_struct(t_args *args, int ac)
{
	printf("Struct contains the next values.\n");
	if (ac == 6)
	{
		printf("N: [%d], die: [%d] eat:[%d], sleep[%d], meals: [%d]\n",
			args->num_of_phil, args->time_to_die, args->time_to_eat, \
			args->time_to_sleep, args->meals_to_have);
	}
	else
		printf("N: [%d], die: [%d] eat:[%d], sleep[%d]\n",
			args->num_of_phil, args->time_to_die, args->time_to_eat, \
			args->time_to_sleep);
}

int	main(int ac, char **av)
{
	t_args	*args;

	if ((ac < 5 || ac > 6) || !valid_args(av, ac))
		return (printf("Error: non valid args\n"), 1);
	args = malloc(sizeof(t_args));
	if (!args)
		return (printf("Error: malloc allocation\n"), 1);
	init_philo(args, av, ac);
	print_struct(args, ac);
	free(args);
	return (0);
}
