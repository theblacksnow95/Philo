/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:01 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/14 16:14:39 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H


typedef struct s_timer
{
	size_t	start;
}	t_timer;

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
	size_t				time_to_eat;
	size_t				time_to_die;
	size_t				time_to_sleep;
	int				meals_to_have;
	t_mutex			*mutex;

}	t_args;

typedef struct s_threads
{
	pthread_t		*thread;
	int				n;
	pthread_t		*id;
	t_args			*args;
	t_timer			timer;


}			t_thread;


#endif

