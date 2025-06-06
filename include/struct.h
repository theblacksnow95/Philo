/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:01 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/06 13:47:05 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct s_mutex
{
	int		total_fork;
	int		status;
}	t_forks;

// struct to store all the philo program arguments.
//	@param num_of_phil 1 or more
//	@param time_to_eat in milliseconds
//	@param time_to_sleep in milliseconds
//	@param [meals_to_have] optional arg in milis, min # of times a phil must eat
typedef struct s_args
{
	int		num_of_phil;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_sleep;
	int		meals_to_have;
	t_forks	*forks;

}	t_args;

typedef struct s_threads
{
	pthread_t	*thread;
	pthread_t	*id;

}			t_thread;

#endif

