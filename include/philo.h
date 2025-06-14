/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/14 19:47:56 by emurillo         ###   ########.fr       */
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

int		ft_atoi(const char *str);
int		error_exit(char *error);
int		valid_args(char **arg, int len);
void	init_philo(t_args *args, char **av, int ac);
void	print_struct(t_args *args, int ac);
int		free_all(t_thread *thread, t_args *args);
size_t	get_current_time(void);
size_t	timer(size_t start);
void	*safe_malloc(size_t bytes);

#endif
