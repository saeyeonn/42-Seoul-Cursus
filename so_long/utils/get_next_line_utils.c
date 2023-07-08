/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:23:57 by saelim            #+#    #+#             */
/*   Updated: 2023/06/18 18:24:00 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dst_len;
	size_t	k;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size < dst_len)
		k = size;
	else
		k = dst_len;
	while (src[i] && dst_len < size - 1 && size)
		dst[dst_len++] = src[i++];
	while (src[i])
		i++;
	dst[dst_len] = '\0';
	return (i + k);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		slen;

	i = 0;
	slen = (int)ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (slen + 1));
	if (!(str))
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	else if (s1 == 0 || s2 == 0)
	{
		if (s1 == 0)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	free(s1);
	ft_strlcat(str + s1_len, s2, s2_len + 1);
	return (str);
}
