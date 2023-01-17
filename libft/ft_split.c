/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:08:32 by saelim            #+#    #+#             */
/*   Updated: 2022/12/27 22:46:23 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			wordcount++;
		i++;
	}
	return (wordcount);
}

int	ft_wordlen(char const *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**free_all(char **arr, int i)
{
	int		j;

	j = 0;
	if (i == 0)
		free(arr[0]);
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return (arr);
}

char	**ft_mksplit(char const *str, char c, char **arr, int cnt)
{
	int	i;
	int	j;
	int	k;
	int	wordlen;

	i = 0;
	k = 0;
	while (str[k] && cnt-- > 0)
	{
		j = 0;
		while (str[k] && str[k] == c)
			k++;
		wordlen = ft_wordlen(str, c, k);
		arr[i] = (char *) malloc(sizeof(char) * (wordlen + 1));
		if (!arr[i])
		{
			arr = free_all(arr, i);
			return (0);
		}
		while (wordlen-- > 0)
			arr[i][j++] = str[k++];
		arr[i++][j] = '\0';
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		wordcount;

	wordcount = ft_wordcount(str, c);
	arr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!arr)
		return (0);
	arr[wordcount] = 0;
	arr = ft_mksplit(str, c, arr, wordcount);
	return (arr);
}
