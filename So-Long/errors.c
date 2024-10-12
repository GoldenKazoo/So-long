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

#include "parsing.h"

int	ft_close_window(t_data *data)
{
	ft_free_all(data);
	free(data -> tab);
	free(data -> map_elements);
	mlx_destroy_image(data -> mlx, data -> empty_tile -> mlx_img);
	free(data -> empty_tile);
	mlx_destroy_image(data -> mlx, data -> wall_tile -> mlx_img);
	free(data -> wall_tile);
	mlx_destroy_image(data -> mlx, data -> player_tile -> mlx_img);
	free(data -> player_tile);
	mlx_destroy_image(data -> mlx, data -> exit_tile -> mlx_img);
	free(data -> exit_tile);
	mlx_destroy_image(data -> mlx, data -> obj_tile -> mlx_img);
	free(data -> obj_tile);
	mlx_destroy_window(data -> mlx, data -> win);
	mlx_destroy_display(data -> mlx);
	free(data -> mlx);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data -> map_height))
	{
		free(data -> tab[i]);
		i++;
	}
}

int	ft_print_error(int state, t_data *data)
{
	if (data -> fd < 0)
	{
		printf("Error can't open map\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 1)
	{
		printf("Error char illegal\n");
		close(data -> fd);
		exit(EXIT_FAILURE);
	}
	if (state == 2)
	{
		printf("Error reading map dimensions.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 3)
	{
		printf("Error no wall around.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 4)
	{
		printf("Error no exit.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 5)
	{
		printf("Error too much exits.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 6)
	{
		printf("Error no player.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 7)
	{
		printf("Error too much player.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 8)
	{
		printf("Error not enough collectible.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	return (0);
}
