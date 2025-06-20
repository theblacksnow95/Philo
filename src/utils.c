/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:09:35 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/20 14:20:53 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(char **arg, int len);
int	is_numeric(char *s);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// void	print_struct(t_args *args, int ac)
// {
// 	printf("Struct contains the next values.\n");
// 	if (ac == 6)
// 	{
//		printf("N: [%ld], die: [%ld] eat:[%ld], sleep[%ld],
//			: [%ld]\n", args->num_of_phil, args->time_to_die,
//			args->time_to_eat, args->time_to_sleep,
//			args->meals_to_have);
// 	}
// 	else
// 		printf("N: [%ld], die: [%ld] eat:[%ld], sleep[%ld]\n",
// 			args->num_of_phil, args->time_to_die, args->time_to_eat,
// 			args->time_to_sleep);
// }

int	valid_args(char **arg, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		puts(arg[i]);
		usleep(300000);
		if (!is_numeric(arg[i]))
			return (error_exit("non numeric.", E_NON_NUMERIC));
		if (ft_strlen(arg[i]) >= 10)
			if (ft_atol(arg[i]) == -1)
				return (error_exit("Error: invalid > INT_MAX.", E_INT_MAX));
		if (i > 1 && i < 5 && ft_strlen(arg[i]) < 2)
			return (error_exit("Error: min 60ms input.", E_MIN_MS));
		if (i > 1 && i < 5 && ft_strlen(arg[i]) == 2)
		{
			if (ft_atol(arg[i]) < 60)
				return (error_exit("Error: value 60ms input.", E_MIN_MS));
		}
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
		if (s[i] == '+')
			i++;
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	long	sign;

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
		num = (num * 10) + str[i++] - '0';
	}
	num = num * sign;
	if (num > INT_MAX || num < INT_MIN)
		num = (-1);
	return (num);
}
