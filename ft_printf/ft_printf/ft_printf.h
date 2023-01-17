/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:00:44 by saelim            #+#    #+#             */
/*   Updated: 2022/12/30 16:34:45 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *c, ...);
int		format(const char c, va_list ap);
int		printchar(int c);
int		printstr(char *str);
int		printaddr(size_t addr);
int		printnbr(int num);
int		printlnb(unsigned int num);
int		printhex(unsigned int num, char c);
void	ft_convert(long long num, unsigned int len, char *str);
char	*ft_itoa(long long num);
char	*ft_hextoa(size_t num, char c);
size_t	ft_div(long long n);

#endif