/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/25 15:49:14 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "struct.h"
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

int		error_exit(char *error, t_code error_code);
int		valid_args(char **arg, int len);
void	data_init(t_args *args, char **av, int ac);
int		free_all(t_args *args);
size_t	get_current_time(void);
size_t	timer(size_t start);
void	*safe_malloc(size_t bytes);
long	ft_atol(const char *str);
int		start_simulation(t_args *args);
void	mili_sleep(long mlsecs);
int		lock_forks(t_thread *philo);
int		unlock_forks(t_thread *philo);
int		mutex_lock(t_fork mutex);
int		mutex_unlock(t_fork mutex);
void	write_status(t_args *args, int n, t_wrcds stat_code);

#endif
