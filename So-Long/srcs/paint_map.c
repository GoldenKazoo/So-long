/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 10:04:17 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_paint_map_aux(t_data *data, int i, int j, t_img *img)
{
	if (data -> tab[j][i] == 'P')
		ft_draw_tile(img, data -> player_tile, i, j);
	if (data -> tab[j][i] == 'E' && data->exit_tile)
		ft_draw_tile(img, data -> exit_tile, i, j);
	if (data -> tab[j][i] == 'C' && data->obj_tile)
		ft_draw_tile(img, data -> obj_tile, i, j);
	if (data -> tab[j][i] == '0' && data->empty_tile)
		ft_draw_tile(img, data -> empty_tile, i, j);
	if (data -> tab[j][i] == '1' && data->wall_tile)
		ft_draw_tile(img, data -> wall_tile, i, j);
}

void	ft_paint_loop(t_data *data, t_img *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < data -> map_h)
	{
		i = 0;
		while (i < data -> map_w)
		{
			ft_paint_map_aux(data, i, j, img);
			i++;
		}
		j++;
	}
}

void	ft_paint_map(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return ;
	img -> mlx_img = mlx_new_image
		(data -> mlx, data -> map_w * 64, data -> map_h * 64);
	img -> addr = mlx_get_data_addr
		(img -> mlx_img, &(img -> bpp), &(img -> line_len), &(img -> endian));
	ft_paint_loop(data, img);
	if (!(img -> addr))
		return ;
	mlx_put_image_to_window(data -> mlx, data -> win, img -> mlx_img, 0, 0);
	mlx_destroy_image(data -> mlx, img -> mlx_img);
	free(img);
}
