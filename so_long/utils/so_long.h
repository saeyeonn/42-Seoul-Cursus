/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:24:41 by saelim            #+#    #+#             */
/*   Updated: 2023/06/18 18:24:43 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define X_EVENT_KEY_RELEASE	2
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define BUFFER_SIZE 	32
# define OPEN_MAX 		10240

typedef struct s_info
{
	char	*map_path;
	int		fd;
	char	**map;
	int		h;
	int		w;
	int		y;
	int		x;
	int		move_cnt;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		img_len;
	int		k_cnt;
	int		can_escape;
	int		**visited;
	void	*mlx;
	void	*win;
	void	*g_img;
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*e_img;
}				t_info;

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
void			ft_putstr_fd(char *s, int fd);
int				get_next_line(int fd, char **line);
int				check_filepath(char *filepath);
void			init_info(t_info *info, char *map_path);
void			free_info(t_info *info);
void			error_exit(char *msg);
void			error_exit_after_free(char *msg, t_info *info);
int				mlx_destroy_exit(t_info *info);
int				check_map_size(t_info *info);
void			allocate_map(t_info *info);
void			check_wall(t_info *info);
void			check_element(t_info *info);
void			parse_map(t_info *info);
void			draw_img(t_info *info, char c, int x, int y);
void			draw_map(t_info *info);
void			move_up(t_info *info);
void			move_left(t_info *info);
void			move_down(t_info *info);
void			move_right(t_info *info);
int				key_connection(int key, t_info *info);
void			check_valid(t_info *info);
void			*ft_memset(void *b, int c, size_t len);
void			key_count(t_info *info, int y, int x);
void			allocate_visit_checker(t_info *info);
void			free_visit_checker(t_info *info);
void			key_search(t_info *info, int y, int x);
void			check_access_all_key(t_info *info);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
