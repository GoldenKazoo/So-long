/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 11:54:22 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <limits.h>
# include "get_next_line.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	char	**tab;
	char	**copy;
	int		*map_elements;
	int		map_w;
	int		map_h;
	int		tile_dim;
	int		p_pos_x;
	int		p_pos_y;
	int		coups;
	int		found_exit;
	int		fd;
	int		quit;
	int		win_size;
	t_img	*empty_tile;
	t_img	*wall_tile;
	t_img	*player_tile;
	t_img	*exit_tile;
	t_img	*obj_tile;
	void	*mlx;
	void	*win;
}	t_data;

int		ft_close_window(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_error1(int state, t_data *data);
void	ft_print_error2(int state, t_data *data);
void	ft_print_error3(int state, t_data *data);
void	ft_print_error4(int state, t_data *data);
void	ft_print_error5(int state, t_data *data);
void	parsing_loop(t_data *data, char *line, char **long_line, int state);
void	ft_free_img(t_data *data);
int		ft_get_pixelcolor(t_img *img, int x, int y);
char	*ft_strdup(char *src);
void	ft_put_pixelimage(t_img *img, int x, int y, int color);
void	ft_draw_tile(t_img *img, t_img *tile, int x, int y);
int		get_pos_x(t_data *data);
int		get_pos_y(t_data *data);
void	ft_free_all(t_data *data);
int		ft_key_hooks(t_data *data);
int		ft_print_error(int state, t_data *data);
void	ft_free_all(t_data *data);
void	ft_paint_map(t_data *data);
t_data	*ft_return_map(t_data *data, int fd);
int		check_map_accessibility(t_data *data);
void	ft_moove_up(int keycode, t_data *data);
void	ft_moove_down(int keycode, t_data *data);
void	ft_moove_right(int keycode, t_data *data);
void	ft_moove_left(int keycode, t_data *data);
int		ft_check_line(t_data *data, char *l);
int		ft_check_first_line(char *line);
int		ft_check_last_line(t_data *data, char *long_line);
int		ft_check_elements(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_data	*ft_data_init(t_data *data, int fd);
void	ft_free_to_error(t_data *data, int state, char *line, char *long_line);
void	ft_free_img(t_data *data);
void	ft_free_all(t_data *data);
t_data	*ft_data_init(t_data *data, int fd);
int		check_map_accessibility(t_data *data);
void	ft_free_all_dup(t_data *data);
int		ft_printf(const char *str, ...);
#endif
