/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:22:11 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/21 17:15:03 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[++i])
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
	}
	return (i);
}

int	ft_putnbr(int n, int *cnt)
{
	long long	temp;
	int			flag;

	temp = (long long) n;
	if (temp < 0)
	{
		temp = temp * -1;
		if (ft_putchar('-') < 0)
			return (-1);
		*cnt += 1;
	}
	if (temp >= 10)
	{
		flag = ft_putnbr(temp / 10, cnt);
		if (flag == -1)
			return (-1);
	}
	if (ft_putchar(temp % 10 + 48) < 0)
		return (-1);
	*cnt += 1;
	return (*cnt);
}

int	ft_sw(unsigned long long nb, char f, int *cnt)
{
	int	flag;

	if (nb >= 16)
	{
		flag = ft_sw(nb / 16, f, cnt);
		if (flag == -1)
			return (-1);
		flag = ft_sw(nb % 16, f, cnt);
		if (flag == -1)
			return (-1);
	}
	else
	{
		if (f == 'x' || f == 'p')
			if (ft_putchar("0123456789abcdef"[nb]) < 0)
				return (-1);
		if (f == 'X')
			if (ft_putchar("0123456789ABCDEF"[nb]) < 0)
				return (-1);
		*cnt += 1;
	}
	return (*cnt);
}

int	ft_putunbr(unsigned int n, int *cnt)
{
	long long	temp;
	int			flag;

	temp = (long long) n;
	if (temp < 0)
	{
		temp = temp * -1;
		if (ft_putchar('-') < 0)
			return (-1);
		*cnt += 1;
	}
	if (temp >= 10)
	{
		flag = ft_putunbr(temp / 10, cnt);
		if (flag == -1)
			return (-1);
	}
	if (ft_putchar(temp % 10 + 48) < 0)
		return (-1);
	*cnt += 1;
	return (*cnt);
}
