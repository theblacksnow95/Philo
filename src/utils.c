/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:09:35 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/07 12:08:06 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_args *args, char **av, int ac)
{
	args->num_of_phil = ft_atoi(av[1]);
	args->time_to_die = (size_t)ft_atoi(av[2]);

	args->time_to_eat = (size_t)ft_atoi(av[3]);
	args->time_to_sleep = (size_t)ft_atoi(av[4]);
	if (ac == 6)
		args->meals_to_have = (size_t)ft_atoi(av[5]);
	if (args->time_to_eat
		&& args->time_to_die && args->time_to_sleep)
		printf("struct init correctly\n");
}

void	print_struct(t_args *args, int ac)
{
	printf("Struct contains the next values.\n");
	if (ac == 6)
	{
		printf("N: [%d], die: [%ld] eat:[%ld], sleep[%ld], meals: [%ld]\n",
			args->num_of_phil, args->time_to_die, args->time_to_eat, \
			args->time_to_sleep, args->meals_to_have);
	}
	else
		printf("N: [%d], die: [%ld] eat:[%ld], sleep[%ld]\n",
			args->num_of_phil, args->time_to_die, args->time_to_eat, \
			args->time_to_sleep);
}

int	valid_args(char **arg, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		puts(arg[i]);
		usleep(300000);
		if (!is_numeric(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (0);
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	num = num * sign;
	return (num);
}

