/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:50:24 by saelim            #+#    #+#             */
/*   Updated: 2022/12/27 21:10:09 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str;
	size_t	length;
	char	*ptr;

	str = ft_strlen(s);
	length = 1;
	if (!s)
		return (0);
	if (str <= start)
		start = 0;
	else if (len > str - start)
		length += str - start;
	else
		length += len;
	ptr = (char *)malloc(sizeof(char) * length);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, length);
	return (ptr);
}
