/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:20:06 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/21 17:15:18 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_specifier(va_list ap, const char *f)
{
	int	cnt;

	cnt = 0;
	if (*f == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*f == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*f == 'd' || *f == 'i')
		return (ft_putnbr(va_arg(ap, int), &cnt));
	if (*f == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int), &cnt));
	if (*f == '%')
		return (ft_putchar('%'));
	if (*f == 'x' || *f == 'X')
		return (ft_sw((unsigned long long)va_arg(ap, unsigned int), *f, &cnt));
	if (*f == 'p')
	{
		if (write(1, "0x", 2) < 0)
			return (-1);
		cnt += 2;
		return (ft_sw((unsigned long long)va_arg(ap, void *), *f, &cnt));
	}
	else
		return (-1);
}

int	ft_printf(const char *f, ...)
{
	int			result;
	int			len;
	va_list		ap;

	result = 0;
	len = 0;
	va_start(ap, f);
	while (*f)
	{
		if (*f == '%')
		{
			len = ft_specifier(ap, f + 1);
			f += 2;
		}
		else
			len = write(1, f++, 1);
		if (len >= 0)
			result += len;
		else
			return (-1);
	}
	va_end(ap);
	return (result);
}
