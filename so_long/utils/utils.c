/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:24:47 by saelim            #+#    #+#             */
/*   Updated: 2023/06/18 18:24:48 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info, char *map_path)
{
	int	img_len;
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_exit("[Error] Can't open your map files");
	close(fd);
	info->map_path = map_path;
	info->move_cnt = 0;
	info->p_cnt = 0;
	info->c_cnt = 0;
	info->e_cnt = 0;
	info->img_len = 64;
	info->mlx = mlx_init();
	info->g_img = mlx_xpm_file_to_image(info->mlx,
			"images/ground.xpm", &img_len, &img_len);
	info->w_img = mlx_xpm_file_to_image(info->mlx,
			"images/wall.xpm", &img_len, &img_len);
	info->p_img = mlx_xpm_file_to_image(info->mlx,
			"images/player.xpm", &img_len, &img_len);
	info->c_img = mlx_xpm_file_to_image(info->mlx,
			"images/key.xpm", &img_len, &img_len);
	info->e_img = mlx_xpm_file_to_image(info->mlx,
			"images/exit.xpm", &img_len, &img_len);
}

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->h)
		free(info->map[i]);
	free(info->map);
}

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error_exit_after_free(char *msg, t_info *info)
{
	ft_putstr_fd(msg, 2);
	free_info(info);
	exit(EXIT_FAILURE);
}

int	mlx_destroy_exit(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	free_info(info);
	exit(EXIT_SUCCESS);
}
