/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:36:30 by saelim            #+#    #+#             */
/*   Updated: 2022/12/25 20:55:10 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	src;
	size_t			i;

	i = 0;
	temp = (unsigned char *) b;
	src = (unsigned char) c;
	while (i < n)
		temp[i++] = src;
	return (temp);
}
