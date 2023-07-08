/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:36:27 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/24 20:47:07 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	count_parsed_argv(char **argv)
{
	char	**parsing_storage;
	int		i;
	int		j;
	int		total_size;

	i = 0;
	j = 0;
	total_size = 0;
	parsing_storage = NULL;
	while (argv[++i])
	{
		j = 0;
		parsing_storage = ft_split(argv[i], ' ');
		while (parsing_storage[j])
			j++;
		total_size += j;
		ft_freeall(parsing_storage, j);
	}
	return (total_size);
}

char	**parse_argv(int cnt, char **argv)
{
	char	**main_storage;
	char	**parsing_storage;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	main_storage = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!main_storage)
		return (NULL);
	while (k < cnt)
	{
		j = -1;
		parsing_storage = ft_split(argv[i], ' ');
		while (parsing_storage[++j])
			main_storage[k++] = ft_strdup(parsing_storage[j]);
		ft_freeall(parsing_storage, j);
		i++;
	}
	main_storage[k] = NULL;
	return (main_storage);
}
