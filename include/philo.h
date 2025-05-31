/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/31 18:25:34 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// struct to store all the philo program arguments.
//	@param num_of_phil 1 or more
//	@param time_to_eat
//	@param time_to_sleep
//	@param [meals_to_have] optional argument, min # of times a phil must eat

typedef struct s_forks
{
	int		total_fork;
	int		status;
}	t_forks;

typedef struct s_args
{
	int		num_of_phil;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_sleep;
	int		meals_to_have;
	t_forks	*forks;

}	t_args;


int	ft_atoi(const char *str);
int	is_numeric(char *s);
int	valid_args(char **arg, int len);

#endif
