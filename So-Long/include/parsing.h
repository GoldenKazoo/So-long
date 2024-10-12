/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/27 16:14:14 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include <limits.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int		*map_elements;
	int		map_width;
	int		map_height;
	int		tile_dim;
	int		p_pos_x;
	int		p_pos_y;
	int		coups;
	int		found_exit;
	int		fd;
	t_img	*empty_tile;
	t_img	*wall_tile;
	t_img	*player_tile;
	t_img	*exit_tile;
	t_img	*obj_tile;
	void	*mlx;
	void	*win;
}	t_data;

int		ft_close_window(t_data *data);
int		ft_get_pixelcolor(t_img *img, int x, int y);
char	*ft_strdup(char *src);
void	ft_put_pixelimage(t_img *img, int x, int y, int color);
void	ft_draw_tile(t_img *img, t_img *tile, int x, int y);
int		get_pos_x(t_data *data);
int		get_pos_y(t_data *data);
void	ft_free_all(t_data *data);
void	ft_count_elements(char c, char *elements);
void	ft_printerror(int error);
int		ft_key_hooks(t_data *data);
void	ft_print_tab(t_data *data);
int		ft_give_dim(t_data *data, int fd);
int		ft_notchar(char c);
int		ft_check_1st(size_t roof, char *line);
int		ft_check_wall_and_char(size_t roof, char *line, char *elements);
int		ft_check_top_bot(t_data *data);
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
int		ft_check_first_last_line(char *line);
int		ft_check_elements(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_data	*ft_data_init(t_data *data, int fd);
