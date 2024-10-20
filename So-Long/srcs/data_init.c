/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:20:16 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/20 14:14:31 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_data_init_img_aux(t_data *data, t_img *img, char *filename)
{
	img->mlx_img = mlx_xpm_file_to_image
		(data->mlx, filename, &(data->tile_dim), &(data->tile_dim));
	if (!img->mlx_img)
	{
		ft_printf("Erreur lors du chargement de l'image %s\n", filename);
		exit(1);
	}
	img->addr = mlx_get_data_addr
		(img->mlx_img, &(img->bpp), &(img->line_len), &(img->endian));
	if (!img->addr)
	{
		ft_printf("Erreur lors de l'obtention des données de l'image\n");
		exit(1);
	}
}

void	ft_data_init_img(t_data *data)
{
	ft_data_init_img_aux(data, data->player_tile, "xpm/Player1.xpm");
	ft_data_init_img_aux(data, data->empty_tile, "xpm/Grass.xpm");
	ft_data_init_img_aux(data, data->wall_tile, "xpm/Wall.xpm");
	ft_data_init_img_aux(data, data->obj_tile, "xpm/Item.xpm");
	ft_data_init_img_aux(data, data->exit_tile, "xpm/Exit.xpm");
}

t_data	*ft_data_init(t_data *data, int fd)
{
	data = ft_return_map(data, fd);
	if (!data || !data->tab)
	{
		ft_printf("Erreur lors du chargement de la carte\n");
		return (NULL);
	}
	data -> mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Erreur: échec de l'initialisation de MLX\n");
		return (NULL);
	}
	data->win = mlx_new_window
		(data->mlx, 64 * data->map_width, 64 * data->map_height, "So long");
	if (!data->win)
	{
		ft_printf("Erreur: échec de la création de la fenêtre\n");
		return (NULL);
	}
	data->tile_dim = 64;
	ft_data_init_img(data);
	data->p_pos_x = get_pos_x(data);
	data->p_pos_y = get_pos_y(data);
	data -> found_exit = 0;
	return (data);
}
