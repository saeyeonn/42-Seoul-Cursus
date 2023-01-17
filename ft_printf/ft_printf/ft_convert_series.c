/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_series.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:19:05 by saelim            #+#    #+#             */
/*   Updated: 2023/01/12 22:42:04 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_div(long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_convert(long long num, unsigned int len, char *str)
{
	if (num == 0)
		str[0] = '0';
	else
	{
		if (num < 0)
		{
			str[0] = '-';
			num *= -1;
		}
		while (num > 0)
		{
			str[len] = num % 10 + '0';
			num /= 10;
			len--;
		}
	}
}

char	*ft_itoa(long long num)
{
	size_t		len;
	char		*str;

	len = ft_div(num);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	ft_convert(num, len, str);
	return (str);
}

char	*ft_hextoa(size_t num, char c)
{
	char	*str;
	size_t	n;
	int		len;

	n = num;
	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}	
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	str[0] = '0';
	while (num > 0)
	{
		if (c == 'x')
			str[len--] = "0123456789abcdef"[num % 16];
		if (c == 'X')
			str[len--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	return (str);
}

int	printhex(unsigned int num, char c)
{
	int		len;
	char	*res;

	len = 0;
	res = ft_hextoa((unsigned long long)num, c);
	if (!res)
		return (-1);
	len += printstr(res);
	free(res);
	return (len);
}
