/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 14:12:54 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
@brief This program checks for valid arguments, and starts a philo simulation.
	the simulations makes all philos, eat, sleep and think for each time.

	@params time_to_die, time_to_eat, time_to_sleep, [min_n_meals]
 */
int	main(int ac, char **av)
{
	t_args			args;

	if ((ac < 5 || ac > 6))
		return (error_exit("Error: Invalid args", ERROR_0), 1);
	if (!valid_args(av, ac))
		return (1);
	data_init(&args, av, ac);
	start_simulation(&args);
	free_all(&args);
	return (0);
}
