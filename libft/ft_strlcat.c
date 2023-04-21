/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:44:53 by saelim            #+#    #+#             */
/*   Updated: 2022/12/25 15:32:58 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t			d_len;
	size_t			s_len;
	unsigned int	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	if (destsize <= d_len)
		return (s_len + destsize);
	while (*dest)
		dest++;
	while (i < s_len && destsize > d_len + 1)
	{
		*(dest++) = src[i++];
		destsize--;
	}
	*dest = '\0';
	return (s_len + d_len);
}
