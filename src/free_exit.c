/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/06 16:34:23 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	free_all(t_thread *thread, t_args *args)
{
	if (!thread ||!thread->thread || !args)
		return (1);
	free(thread->thread);
	free(thread);
	free(args);
	return (0);
}
