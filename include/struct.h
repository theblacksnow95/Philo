/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:01 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/06 16:50:29 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct s_mutex
{
	pthread_mutex_t		mutex;
	struct s_mutex		*next;
}	t_mutex;

// struct to store all the philo program arguments.
//	@param num_of_phil 1 or more
//	@param time_to_eat in milliseconds
//	@param time_to_sleep in milliseconds
//	@param [meals_to_have] optional arg in milis, min # of times a phil must eat
typedef struct s_args
{
	int				num_of_phil;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_die;
	suseconds_t		time_to_sleep;
	suseconds_t		meals_to_have;
	t_mutex			*mutex;

}	t_args;

typedef struct s_threads
{
	pthread_t	*thread;
	pthread_t	*id;

}			t_thread;

#endif

