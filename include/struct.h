/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:01 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/27 18:22:24 by emurillo         ###   ########.fr       */
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
	E_LOCK,
	E_THREAD,
}	t_code;

typedef enum e_write
{
	EAT,
	SLEEPING,
	DIED,
	THINK,
	TAKE_LEFT_FORK,
	TAKE_RIGHT_FORK,
	RET_LEFT_FORK,
	RET_RIGHT_FORK,
	TRUE,
	FALSE,
}	t_wrcds;

typedef struct s_timer
{
	size_t	start;
}	t_timer;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				mutex_id;
}	t_mutex;

typedef struct s_fork
{
	pthread_mutex_t	fork;
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
	int				all_running;
	int				count_running;
	int				dinner_end;
	t_fork			*mutex;
	t_mutex			write;
	t_mutex			smtx;
	t_thread		*threads;
	pthread_t		monitor;
	t_timer			timer;

}	t_args;

typedef struct s_threads
{
	int				n;
	long			last_meal;
	int				full;
	int				n_meals;
	t_fork			*right_fork;
	t_fork			*left_fork;
	pthread_t		id;
	t_args			*args;
}			t_thread;

#endif
