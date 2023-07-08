/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:24:13 by saelim            #+#    #+#             */
/*   Updated: 2023/06/18 18:24:15 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_search(t_info *info, int y, int x)
{
	if (y < 0 || y >= info->h || x < 0 || x >= info->w || info->visited[y][x])
		return ;
	if (!info->visited[y][x])
	{
		if (info->map[y][x] == '0')
			key_count(info, y, x);
		else if (info->map[y][x] == 'C')
		{
			info->k_cnt++;
			key_count(info, y, x);
		}
		else if (info->map[y][x] == 'E')
			info->can_escape = 1;
	}
}

void	check_access_all_key(t_info *info)
{
	key_count(info, info->y, info->x);
	free_visit_checker(info);
	if (info->k_cnt != info->c_cnt)
		error_exit_after_free("Item Access Error Exception", info);
	else if (!(info->can_escape))
		error_exit_after_free("Unable Exit Error Exception", info);
}

void	key_count(t_info *info, int y, int x)
{
	if (y < 0 || y >= info->h || x < 0 || x >= info->w || info->visited[y][x])
		return ;
	info->visited[y][x] = 1;
	key_search(info, y - 1, x);
	key_search(info, y + 1, x);
	key_search(info, y, x - 1);
	key_search(info, y, x + 1);
}

void	allocate_visit_checker(t_info *info)
{
	int	i;

	i = -1;
	info->visited = (int **)malloc(info->h * sizeof(int *) + 1);
	if (info->visited == NULL)
		return ;
	while (++i < info->h)
	{
		info->visited[i] = (int *)malloc(info->w * sizeof(int));
		if (info->visited[i] == NULL)
			return ;
		ft_memset(info->visited[i], 0, info->w * sizeof(int));
	}
}

void	free_visit_checker(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info -> h)
		free(info->visited[i]);
	free(info->visited);
}
