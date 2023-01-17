/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:06:56 by saelim            #+#    #+#             */
/*   Updated: 2022/12/27 21:37:29 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char const *s1, char const *s2, char *str)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;
	char			*ptr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	ptr = str;
	while (len1 > 0)
	{
		*(ptr++) = s1[i++];
		len1--;
	}
	i = 0;
	while (len2 > 0)
	{
		*(ptr++) = s2[i++];
		len2--;
	}
	*ptr = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	str = ft_strcpy(s1, s2, str);
	return (str);
}
