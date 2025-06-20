/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/20 18:12:07 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args			args;

	if ((ac < 5 || ac > 6))
		return (error_exit("Error: Invalid args", ERROR_0), 1);
	if (!valid_args(av, ac))
		return (1);
	init_philo(&args, av, ac);
	start_simulation(&args);
	free_all(&args);
	return (0);
}
