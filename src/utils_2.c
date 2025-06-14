/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:09:35 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/14 18:47:04 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void *var;

	var = malloc(bytes);
	if (!var)
		return (NULL);
	return (var);
}

size_t	timer(size_t start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		printf("gettimeofday() error\n");
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() errror\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
