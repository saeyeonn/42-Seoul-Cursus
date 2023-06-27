# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_convert(long long num, unsigned int len, char *str)
{
	str[0] = '0';
	
    if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	
    while (num > 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
}

char	*ft_itoa(long long num)
{
	size_t		len = 0;;
    long long n = num;

    if (n <= 0)
    {
        len += 1;
        n *= -1;
    }    
	while (n > 0)
    {
        len++;
        n /= 10;   
    }

	char *str = (char *) malloc(len + 1);
	if (!str)
		return (0);

	str[len--] = '\0';
	ft_convert(num, len, str);
	return (str);
}

char	*ft_hextoa(size_t num)
{
	size_t	n = num;
	int		len = 1;

	while (n >= 16)
	{
		n /= 16;
		len++;
	}	

	char *str = (char *) malloc(len + 1);
	if (!str)
		return (0);

	str[0] = '0';
	str[len--] = '\0';

    while (num > 0)
	{
		str[len--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}

	return (str);
}

int	printstr(char *str)
{
	int	len, err = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
    {
        err = write(1, &str[len++], 1);
		if ( err== -1)
			return (-1);
    }

	return (len);
}

int	printnbr(int num)
{
	char	*res = ft_itoa((long long) num);
	if (!res)
		return (-1);

	int len = printstr(res);
	free(res);

	return (len);
}

int	printhex(unsigned int num)
{
    char	*res = ft_hextoa((unsigned long long)num);
	if (!res)
		return (-1);
	
    int len = printstr(res);
	free(res);
	
    return (len);
}

int format(const char c, va_list ap)
{
    if (c == 's')
		return (printstr((char *)va_arg(ap, char *)));
    else if (c == 'd')
		return (printnbr((int)va_arg(ap, int)));
    else if (c == 'x')
		return (printhex((unsigned int)va_arg(ap, unsigned int)));
    else
        return -1;    
}

int ft_printf(const char *c, ...)
{
    int len, res = 0;
    va_list ap;
    va_start(ap, c);

    while (*c)
    {
        if (*c == '%')
        {
            res = format(*(c + 1), ap);
            c += 2;
        }    
        else
            res = write(1, c++, 1);
        if (res < 0)
        {
            va_end(ap);
            return -1;
        }
        len += res;
    }
    va_end(ap);

    return len;
}
