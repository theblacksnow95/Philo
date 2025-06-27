/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 15:26:22 by emurillo         ###   ########.fr       */
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

// data init and args validation, parsing

int			error_exit(char *error, t_code error_code);
int			valid_args(char **arg, int len);
void		data_init(t_args *args, char **av, int ac);
int			free_all(t_args *args);
long		ft_atol(const char *str);

// time functions calculate time in millisecs and sleep in millisecs

size_t		get_current_time(void);
size_t		timer(size_t start);
void		mili_sleep(long mlsecs);

// Main functions and utils, start simulation and manage mutexes and forks

void		*safe_malloc(size_t bytes);
int			start_simulation(t_args *args);
int			lock_forks(t_thread *philo);
int			unlock_forks(t_thread *philo);
int			mutex_lock(t_mutex mutex);
int			mutex_unlock(t_mutex mutex);
void		write_status(t_thread *philo, int n, t_wrcds stat_code);
void		wait_all_threads(t_args *args);
void		wait_all_threads(t_args *args);
t_wrcds		check_all_created(t_args *args);
void		set_all_created(t_args *args);
void		set_running(t_args *args, int *value);
void		set_last_meal(t_thread *philo);

// monitoring function to check when they die

void		monitoring(t_args *args);

// single routine for 1 philosopher

void		single_routine(t_thread *philo, t_args *args);

#endif
