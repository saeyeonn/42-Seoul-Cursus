/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:56:47 by saelim            #+#    #+#             */
/*   Updated: 2023/04/29 20:56:47 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_btoa(int sig) // always excuted : translate bits
{
	static int	bit; // set bit location
	static int	i; // collection of set bits

	if (sig == SIGUSR1)
		i |= (0x01 << bit); // i's bit th bit = 1
	bit++;
	if (bit == 8)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	pid = getpid();
	ft_putnbr(pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa); // enroll Signal Handler func.
		signal(SIGUSR2, ft_btoa); // signal -> call enrolled func.
		pause();
	}
	return (0);
}