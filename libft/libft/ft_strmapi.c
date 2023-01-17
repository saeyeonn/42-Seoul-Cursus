/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:26:38 by saelim            #+#    #+#             */
/*   Updated: 2022/12/25 22:57:50 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;	
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str || !f)
		return (NULL);
	if (!len)
		return (str);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
