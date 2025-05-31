/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_example.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:13:28 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/31 15:53:14 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_mutex
{
	int				amount;
	pthread_mutex_t	*mutex;
}			t_mutex;


// the initial balance is 0
int	balance = 0;

// write the new balance (after as simulated 1/4 second delay)
void	write_balance(int new_balance)
{
	usleep(250000);
	balance = new_balance;
}

// returns the balance (after a simulated 1/4 seond delay)
int	read_balance(void)
{
	usleep(250000);
	return (balance);
}

// carry out a deposit
void	*deposit(void *amount)
{
	t_mutex	*arg;

	arg = (t_mutex *)amount;
	// lock the mutex
	printf("start deposit of amount == %d\n", arg->amount);
	pthread_mutex_lock(arg->mutex);

	// retrieve the bank balance
	int account_balance = read_balance();

	// make the update locally
	account_balance += (arg->amount);

	// write the new bank balance
	write_balance(account_balance);

	// unlock to make the critical section available to other threads
	pthread_mutex_unlock(arg->mutex);

	return (NULL);
}

int	main(void)
{
	// mutex variable
	pthread_t		thread1;
	pthread_t		thread2;
	pthread_mutex_t	mutex;
	t_mutex			*deposit1;
	t_mutex			*deposit2;

	deposit1 = malloc(sizeof(t_mutex));
	deposit2 = malloc(sizeof(t_mutex));
	// output the balance before the deposits
	int before = read_balance();
	printf("Before: %d\n", before);
	// initialize the mutex
	pthread_mutex_init(&mutex, NULL);

	// the deposit amounts... the correct total afterwards should be 500
	deposit1->amount = 300;
	deposit1->mutex = &mutex;
	deposit2->amount = 200;
	deposit2->mutex = &mutex;


	// create threads to run the deposit function with these deposit amounts
	pthread_create(&thread1, NULL, deposit, deposit1);
	pthread_create(&thread2, NULL, deposit,  deposit2);

	// join the threads
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	 // destroy the mutex
	pthread_mutex_destroy(&mutex);

	// output the balance after the deposits
	int after = read_balance();
	printf("After: %d\n", after);

	return 0;
}
