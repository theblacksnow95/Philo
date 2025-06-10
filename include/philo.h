/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/10 16:04:16 by emurillo         ###   ########.fr       */
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

int		ft_atoi(const char *str);
int		is_numeric(char *s);
int		valid_args(char **arg, int len);
void	init_philo(t_args *args, char **av, int ac);
void	print_struct(t_args *args, int ac);
int		free_all(t_thread *thread, t_args *args);
size_t		get_current_time(void);

#endif
