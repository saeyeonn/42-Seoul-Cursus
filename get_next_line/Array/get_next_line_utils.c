/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:41:32 by saelim            #+#    #+#             */
/*   Updated: 2023/04/20 16:54:49 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1)
	{
        s1 = malloc(1);
		if (!s1)
		    return (0);
	    s1[0] = 0;
    }
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (ft_free(&s1));
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (ptr);
}


char	*ft_strchr(char *s, char c)
{
	char	temp;

	temp = c;
	while (*s)
	{
		if (*s == temp)
			return ((char *) s);
		s++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	length;

	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if (s_len <= start)
	{
		start = 0;
		length = 1;
	}
	else if (len > s_len - start)
		length = s_len - start + 1;
	else
		length = len + 1;
	ptr = (char *)malloc(sizeof(char) * length);
	if (!ptr)
		return (0);
	ft_strlcpy (ptr, s + start, length);
	return (ptr);
}