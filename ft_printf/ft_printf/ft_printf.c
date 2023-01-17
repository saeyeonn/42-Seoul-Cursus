/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:00:57 by saelim            #+#    #+#             */
/*   Updated: 2022/12/30 17:02:15 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(const char c, va_list ap)
{
	if (c == 'c')
		return (printchar((int)va_arg(ap, int)));
	else if (c == 's')
		return (printstr((char *)va_arg(ap, char *)));
	else if (c == 'p')
		return (printaddr((size_t)va_arg(ap, size_t)));
	else if (c == 'd' || c == 'i')
		return (printnbr((int)va_arg(ap, int)));
	else if (c == 'u')
		return (printlnb((unsigned int)va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (printhex((unsigned int)va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *c, ...)
{
	int		len;
	int		ret;
	va_list	ap;

	len = 0;
	ret = 0;
	va_start(ap, c);
	while (*c)
	{
		if (*c == '%')
		{
			ret = format(*(c + 1), ap);
			c += 2;
		}
		else
			ret = write(1, c++, 1);
		if (ret >= 0)
			len += ret;
		else
			return (-1);
	}
	va_end(ap);
	return (len);
}
