/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:03 by saelim            #+#    #+#             */
/*   Updated: 2023/01/04 15:02:10 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_checklen(char *str, int nflag, int end)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n' && nflag)
		return (i);
	while (str[i] != '\0')
		i++;
	if (end)
		return (i);
	return (-1);
}

int	ft_strnode(t_list *node, char *buff, int byte)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	if (node->str)
		while ((node->str)[len])
			len++;
	result = (char *)malloc(len + byte + 1);
	if (!result)
		return (1);
	i = -1;
	while (++i < len)
		result[i] = (node->str)[i];
	i = -1;
	while (++i < byte)
		result[len + i] = buff[i];
	result[len + byte] = '\0';
	free(node->str);
	node->str = result;
	return (ft_checklen(node->str, 1, 0));
}

char	*ft_substr(char *str, int start, int len, int nflag)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(len + nflag + 1);
	if (!result)
		return (NULL);
	while (i < len + nflag)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_newline(t_list *node)
{
	int		nflag;
	int		end;
	char	*before;
	char	*after;

	nflag = ft_checklen(node->str, 1, 0);
	end = ft_checklen(node->str, 0, 1);
	if (end - nflag == 1 || nflag < 0)
	{
		before = ft_substr(node->str, 0, end, 0);
		after = NULL;
	}
	else
	{
		before = ft_substr(node->str, 0, nflag, 1);
		after = ft_substr(node->str, nflag + 1, end - nflag - 1, 0);
		if (!after)
			return (NULL);
	}
	if (!before)
		return (NULL);
	free(node->str);
	node->str = after;
	return (before);
}
