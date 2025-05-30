/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:44:22 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/30 18:18:08 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The thread if not sleep will take longer than the main to finish, so
// using usleep will wait for it to finish, same that the pthread_join func

void	*test(void *arg)
{
	int	i;
	int	n;

	i = 0;
	n = *(int *) arg;
	while (i < n)
	{
		printf("Test #%d\n", i + 1);
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int			n;
	pthread_t	thread1;

	if (ac != 2 || !av[1])
		return (1);
	n = atoi(av[1]);
	pthread_create(&thread1, NULL, test, (void *)&n);
	usleep(80);
	pthread_cancel(thread1);
	pthread_join(thread1, NULL);
	return (0);
}
