/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:24:28 by saelim            #+#    #+#             */
/*   Updated: 2023/06/18 18:24:30 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_info *info)
{
	if (info->map[info->y - 1][info->x] == '1')
		return ;
	else if (info->map[info->y - 1][info->x] == 'E')
	{
		if (info->c_cnt != 0)
			return ;
		ft_putstr_fd("move count : ", 1);
		ft_putnbr_fd(info->move_cnt + 1, 1);
		ft_putchar_fd('\n', 1);
		mlx_destroy_exit(info);
	}
	else if (info->map[info->y - 1][info->x] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y - 1][info->x] = 'P';
	info->move_cnt++;
	info->y--;
	ft_putstr_fd("move count : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putchar_fd('\n', 1);
}

void	move_left(t_info *info)
{
	if (info->map[info->y][info->x - 1] == '1')
		return ;
	else if (info->map[info->y][info->x - 1] == 'E')
	{
		if (info->c_cnt != 0)
			return ;
		ft_putstr_fd("move count : ", 1);
		ft_putnbr_fd(info->move_cnt + 1, 1);
		ft_putchar_fd('\n', 1);
		mlx_destroy_exit(info);
	}
	else if (info->map[info->y][info->x - 1] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y][info->x - 1] = 'P';
	info->move_cnt++;
	info->x--;
	ft_putstr_fd("move count : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_info *info)
{
	if (info->map[info->y + 1][info->x] == '1')
		return ;
	else if (info->map[info->y + 1][info->x] == 'E')
	{
		if (info->c_cnt != 0)
			return ;
		ft_putstr_fd("move count : ", 1);
		ft_putnbr_fd(info->move_cnt + 1, 1);
		ft_putchar_fd('\n', 1);
		mlx_destroy_exit(info);
	}
	if (info->map[info->y + 1][info->x] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y + 1][info->x] = 'P';
	info->move_cnt++;
	info->y++;
	ft_putstr_fd("move count : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putchar_fd('\n', 1);
}

void	move_right(t_info *info)
{
	if (info->map[info->y][info->x + 1] == '1')
		return ;
	else if (info->map[info->y][info->x + 1] == 'E')
	{
		if (info->c_cnt != 0)
			return ;
		ft_putstr_fd("move count : ", 1);
		ft_putnbr_fd(info->move_cnt + 1, 1);
		ft_putchar_fd('\n', 1);
		mlx_destroy_exit(info);
	}
	if (info->map[info->y][info->x + 1] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y][info->x + 1] = 'P';
	info->move_cnt++;
	info->x++;
	ft_putstr_fd("move count : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putchar_fd('\n', 1);
}

int	key_connection(int key, t_info *info)
{
	if (key == KEY_W)
		move_up(info);
	else if (key == KEY_A)
		move_left(info);
	else if (key == KEY_S)
		move_down(info);
	else if (key == KEY_D)
		move_right(info);
	else if (key == KEY_ESC)
		mlx_destroy_exit(info);
	else
		return (0);
	draw_map(info);
	return (1);
}
