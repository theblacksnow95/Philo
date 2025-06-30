/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/30 18:59:48 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(char *error, t_code error_code)
{
	if (error_code == ERROR_0)
		return (printf("%s\n", error), 0);
	if (error_code == E_NON_NUMERIC)
		return (printf("Error: %s\n", error), 0);
	if (error_code == E_MIN_MS)
		return (printf("Error: %s\n", error), 0);
	if (error_code == E_FREE)
		return (printf("Error: %s\n", error), 0);
	if (error_code == E_LOCK)
		return (printf("Error: %s\n", error), 0);
	if (error_code == E_THREAD)
		return (printf("Error: %s\n", error), 0);
	return (0);
}

/*
	@brief function used to free all the structs and mutexes at the exit.
	it will destroy the mutexes even if we do not need to as they are
	POSIX functions that do not allocate memory.

	@param t_args* args: pointer to arguments used that will be freed.
*/
int	free_all(t_args *args)
{
	int	i;

	i = 0;
	if (!args)
		return (error_exit("Error at free review free", E_FREE));
	while (i < args->num_of_phil)
	{
		pthread_mutex_destroy(&args->mutex[i].fork);
		i++;
	}
	pthread_mutex_destroy(&args->smtx.mutex);
	free(args->threads);
	free(args->mutex);
	return (0);
}
