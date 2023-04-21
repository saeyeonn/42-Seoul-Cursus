/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:46:03 by saelim            #+#    #+#             */
/*   Updated: 2022/12/25 17:39:20 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*dup;
	char			*d_ptr;
	unsigned int	i;

	i = 0;
	dup = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (0);
	d_ptr = dup;
	while (i < ft_strlen(src))
		*(dup++) = src[i++];
	*dup = '\0';
	return (d_ptr);
}
