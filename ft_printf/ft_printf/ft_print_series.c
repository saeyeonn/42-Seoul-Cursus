/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_series.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 01:15:32 by saelim            #+#    #+#             */
/*   Updated: 2022/12/30 17:00:34 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int c)
{
	return (write(1, &c, 1));
}

int	printstr(char *str)
{
	int	len;
	int	err;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		err = write(1, &str[len++], 1);
		if (err == -1)
			return (-1);
	}
	return (len);
}

int	printnbr(int num)
{
	int		len;
	char	*res;

	res = ft_itoa((long long) num);
	if (!res)
		return (-1);
	len = printstr(res);
	free(res);
	return (len);
}

int	printlnb(unsigned int num)
{
	int		len;
	char	*res;

	res = ft_itoa((long long) num);
	if (!res)
		return (-1);
	len = printstr(res);
	free(res);
	return (len);
}

int	printaddr(size_t addr)
{
	int		len;
	char	*res;

	len = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	res = ft_hextoa(addr, 'x');
	if (!res)
		return (-1);
	len += printstr(res);
	free(res);
	return (len);
}
