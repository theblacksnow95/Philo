/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:23:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/24 11:32:33 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_forks(t_thread *philo)
{
	if(pthread_mutex_lock(&philo->left_fork->fork) == -1)
	{
		return (error_exit("lock mutex", E_LOCK), 1);
	}

	if (pthread_mutex_lock(&philo->right_fork->fork) == -1)
	{
		return (error_exit("lock mutex", E_LOCK), 1);
	}
	return (0);
}

int	unlock_forks(t_thread *philo)
{
	if(pthread_mutex_unlock(&philo->left_fork->fork) == -1)
	{
		return (error_exit("unlock mutex", E_LOCK), 1);
	}

	if (pthread_mutex_unlock(&philo->right_fork->fork) == -1)
	{
		return (error_exit("unlock mutex", E_LOCK), 1);
	}
	return (0);
}
