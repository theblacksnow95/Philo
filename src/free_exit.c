/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:52 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/06 13:56:15 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	free_all(t_thread *thread)
{
	if (!thread ||!thread->thread)
		return (0);
	free(thread->thread);
	free(thread);
	return (0);
}
