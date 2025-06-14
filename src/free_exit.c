/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:17 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error_exit(char *error)
{
	printf("%s\n", error);
	return (-1);
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
