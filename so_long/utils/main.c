/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:24:20 by saelim            #+#    #+#             */
/*   Updated: 2023/06/18 18:24:23 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filepath(char *filepath)
{
	int	i;

	i = ft_strlen(filepath);
	if (i < 5)
		return (0);
	if (filepath[i - 4] != '.' || filepath[i - 3] != 'b' || \
			filepath[i - 2] != 'e' || filepath[i - 1] != 'r')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || !check_filepath(argv[1]))
		error_exit("File Path Error Exception");
	init_info(&info, argv[1]);
	parse_map(&info);
	info.win = mlx_new_window(info.mlx, info.img_len * info.w,
			info.img_len * info.h, "Saelim's Pochacco Mini Game");
	draw_map(&info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_connection, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &mlx_destroy_exit, &info);
	mlx_loop(info.mlx);
	return (0);
}
