/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/14 17:22:30 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "parsing.h"
#include <fcntl.h> // pour open()

void	ft_data_init_img_aux(t_data *data, t_img *img, char *filename)
{
	img->mlx_img = mlx_xpm_file_to_image
		(data->mlx, filename, &(data->tile_dim), &(data->tile_dim));
	if (!img->mlx_img)
	{
		printf("Erreur lors du chargement de l'image %s\n", filename);
		exit(1);
	}
	img->addr = mlx_get_data_addr
		(img->mlx_img, &(img->bpp), &(img->line_len), &(img->endian));
	if (!img->addr)
	{
		printf("Erreur lors de l'obtention des données de l'image\n");
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
		printf("Erreur lors du chargement de la carte\n");
		return (NULL);
	}
	data -> mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Erreur: échec de l'initialisation de MLX\n");
		return (NULL);
	}
	data->win = mlx_new_window
		(data->mlx, 64 * data->map_width, 64 * data->map_height, "So long");
	if (!data->win)
	{
		printf("Erreur: échec de la création de la fenêtre\n");
		return (NULL);
	}
	data->tile_dim = 64;
	ft_data_init_img(data);
	data->p_pos_x = get_pos_x(data);
	data->p_pos_y = get_pos_y(data);
	data -> found_exit = 0;
	return (data);
}

int	ft_check_arg_fd(int argc, char **argv, t_data *data)
{
	int	len;

	if (argc != 2)
	{
		printf("Error, to use: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", len) != 0)
	{
		printf("Error: filename must finish with .ber\n");
		return (1);
	}
	data -> fd = open(argv[1], O_RDONLY);
	if (data -> fd < 0)
	{
		printf("Error: can't open file");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (argv[1] == NULL)
	{
		free(data);
		return (1);
	}
	if (ft_check_arg_fd(argc, argv, data) == 1)
	{
		free(data);
		return (1);
	}
	data->player_tile = malloc(sizeof(t_img));
	data->empty_tile = malloc(sizeof(t_img));
	data->wall_tile = malloc(sizeof(t_img));
	data->obj_tile = malloc(sizeof(t_img));
	data->exit_tile = malloc(sizeof(t_img));
	data = ft_data_init(data, data -> fd);
	if (!data)
	{
		return (1);
	}
	ft_paint_map(data);
	ft_key_hooks(data);
	mlx_hook(data->win, 17, 0, (int (*)())ft_close_window, data);
	mlx_loop(data->mlx);
	ft_free_all(data);
	return (0);
}
