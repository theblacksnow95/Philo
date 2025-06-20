/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:01 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/20 16:44:51 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct s_threads	t_thread;

typedef enum e_codes
{
	ERROR_0,
	E_NON_NUMERIC,
	E_INT_MAX,
	E_MIN_MS,
	E_FREE,
}	t_code;

typedef struct s_timer
{
	size_t	start;
}	t_timer;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	int				fork_id;
}	t_fork;

// struct to store all the philo program arguments.
//	@param num_of_phil 1 or more
//	@param time_to_eat in milliseconds
//	@param time_to_sleep in milliseconds
//	@param [meals_to_have] optional arg in milis, min # of times a phil must eat
typedef struct s_args
{
	long			num_of_phil;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long			meals_to_have;
	int				all_created;
	t_fork			*mutex;
	t_thread		*threads;

}	t_args;

typedef struct s_threads
{
	int				n;
	long			last_meal;
	t_fork			right_fork;
	t_fork			left_fork;
	pthread_t		*id;
	t_timer			timer;
	t_args			*args;


}			t_thread;


#endif

