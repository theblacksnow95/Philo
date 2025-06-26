/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:23:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/26 14:30:38 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_lock(t_mutex mutex)
{
	if (pthread_mutex_lock(&mutex.mutex) == -1)
		return (error_exit("lock mutex", E_LOCK), 1);
	return (0);
}

int	mutex_unlock(t_mutex mutex)
{
	if (pthread_mutex_unlock(&mutex.mutex) == -1)
		return (error_exit("unlock mutex", E_LOCK), 1);
	return (0);
}

int	lock_forks(t_thread *philo)
{
	if (pthread_mutex_lock(&philo->left_fork->fork) == -1)
		return (error_exit("lock mutex", E_LOCK), 1);
	write_status(philo, philo->n, TAKE_LEFT_FORK);
	if (pthread_mutex_lock(&philo->right_fork->fork) == -1)
		return (error_exit("lock mutex", E_LOCK), 1);
	write_status(philo, philo->n, TAKE_RIGHT_FORK);
	return (0);
}

int	unlock_forks(t_thread *philo)
{
	if (pthread_mutex_unlock(&philo->left_fork->fork) == -1)
		return (error_exit("unlock mutex", E_LOCK), 1);
	write_status(philo, philo->n, RET_LEFT_FORK);
	if (pthread_mutex_unlock(&philo->right_fork->fork) == -1)
		return (error_exit("unlock mutex", E_LOCK), 1);
	write_status(philo, philo->n, RET_LEFT_FORK);
	return (0);
}
