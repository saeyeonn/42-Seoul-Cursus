/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:55:29 by saelim            #+#    #+#             */
/*   Updated: 2023/04/29 20:55:29 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	i;
	long long		num;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	sign = (int)(sign * num);
	return (sign);
}


void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1,"Error\n", 6);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_atob(pid, argv[2][i]);
		i++;
	}
	return (0);
}