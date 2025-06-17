/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/17 16:04:23 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error_exit(char *error, t_code error_code)
{
	if (error_code == ERROR_0)
		return (printf("%s\n", error), 0);
	if (error_code == E_NON_NUMERIC)
		return (printf("Error: %s\n", error), 0);
	if (error_code == E_MIN_MS)
		return (printf("Error: %s\n", error), 0);
	return (0);
}

int	free_all(t_thread *thread, t_args *args)
{
	if (!thread ||!thread->thread || !args)
		return (1);
	free(args);
	free(thread->thread);
	free(thread);
	return (0);
}
