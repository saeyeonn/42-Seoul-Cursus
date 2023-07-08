/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:48:45 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/21 17:14:26 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;

	i = -1;
	str_len = ft_strlen (s1);
	ptr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!ptr)
		return (0);
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	ptr[i] = s1[i];
	return (ptr);
}
