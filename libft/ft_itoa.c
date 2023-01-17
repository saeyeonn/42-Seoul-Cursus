/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:19:05 by saelim            #+#    #+#             */
/*   Updated: 2022/12/27 21:24:20 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	long long	num;
	size_t		len;
	char		*str;

	num = (long long) n;
	len = ft_div(num);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	ft_convert(num, len, str);
	return (str);
}
